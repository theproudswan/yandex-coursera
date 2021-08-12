#include "test_runner.h"
#include "profile.h"

#include <map>
#include <string>
#include <string_view>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <future>
#include <cmath>

using namespace std;


///////////////////////// BEGIN OF PAGINATOR /////////////////////////////
template <typename Iterator>
class IteratorRange
{
public:
    IteratorRange(Iterator begin, Iterator end)
        : first(begin)
        , last(end)
        , size_(distance(first, last))
    {
    }

    Iterator begin() const
    {
        return first;
    }

    Iterator end() const
    {
        return last;
    }

    size_t size() const
    {
        return size_;
    }

private:
    Iterator first, last;
    size_t size_;
};

template <typename Iterator>
class Paginator
{
private:
    std::vector<IteratorRange<Iterator>> pages;

public:
    Paginator(Iterator begin, Iterator end, size_t page_size)
    {
        for (size_t left = std::distance(begin, end); left > 0; )
        {
            size_t current_page_size = std::min(page_size, left);
            Iterator current_page_end = std::next(begin, current_page_size);
            pages.push_back({ begin, current_page_end });

            left -= current_page_size;
            begin = current_page_end;
        }
    }

    auto begin() const
    {
        return pages.begin();
    }

    auto end() const
    {
        return pages.end();
    }

    size_t size() const
    {
        return pages.size();
    }
};

template <typename C>
auto Paginate(C& c, size_t page_size)
{
    return Paginator(begin(c), end(c), page_size);
}

//////////////////////////////// END OF PAGINATOR ////////////////////////////////

struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other){
      for (auto [word, frequences] : other.word_frequences){
          word_frequences[word] += frequences;
      }
  }
};

Stats ExploreLine(const set<string>& key_words, const string& line) {
    Stats words;
    string_view line_view(line);

    auto pos_view = line_view.find_first_not_of(" ");
    line_view.remove_prefix(pos_view);

    while (pos_view != std::string_view::npos)
    {

        pos_view = line_view.find_first_of(" ");
        auto key = string(line_view.substr(0, pos_view));

        if (key_words.count(key) > 0)
        {
            words.word_frequences[move(key)]++;
        }

        if (pos_view == string::npos)
        {
            break;
        }
        else
        {
            line_view.remove_prefix(pos_view + 1);
        }
    }
    return words;
}

Stats ExploreKeyWordsSingleThread(
  const set<string>& key_words, istream& input
) {
   Stats result;
  string tmp;
  while (input >> tmp){
      if (key_words.find(tmp) != key_words.end()){
          result.word_frequences[tmp] += 1;
      }
  }
  return result;
}

Stats ExploreKeyWordsMultiThread(
  const set<string>& key_words, istream& input
) {
   Stats result;
   vector<string> lines;
    
	string line;
    while (getline(input, line)){
        lines.push_back(line);
    }

    float threads_count = 4.0;
    size_t page_size = min<size_t>(lines.size(), ceil(lines.size() / threads_count));
    vector<future<Stats>> futures;

    for (const auto& page : Paginate(lines, page_size)){
        futures.push_back(async([&key_words, page]{
                Stats res;
                for(const auto& line : page){
                    res += ExploreLine(key_words, line); 
                }
                return res;
		}));
    }
  for (auto& f : futures){
      result += f.get();
  }
  return result;
}

// Stats ExploreKeyWords(const set<string>& key_words, istream& input) { // Переделать на многопоточность, где отдельный поток 
//                                                                       // будет исследовать отдельную строку
//   // Реализуйте эту функцию
//   Stats result;
//   string tmp;
//   while (input >> tmp){
//       if (key_words.find(tmp) != key_words.end()){
//           result.word_frequences[tmp] += 1;
//       }
//   }
//   return result;
// }
Stats ExploreKeyWords(const set<string>& key_words, istream& input) { // Переделать на многопоточность, где отдельный поток 
                                                                      // будет исследовать отдельную строку
  // Реализуйте эту функцию
  // return ExploreKeyWordsSingleThread(key_words, input);
  return ExploreKeyWordsMultiThread(key_words, input);
}

void TestBasic() {
  const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

  stringstream ss;
  ss << "this new yangle service really rocks\n";
  ss << "It sucks when yangle isn't available\n";
  ss << "10 reasons why yangle is the best IT company\n";
  ss << "yangle rocks others suck\n";
  ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

  const auto stats = ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
    {"yangle", 6},
    {"rocks", 2},
    {"sucks", 1}
  };
  ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
  //LOG_DURATION("Single thread");
  TestRunner tr;
  RUN_TEST(tr, TestBasic);
}
