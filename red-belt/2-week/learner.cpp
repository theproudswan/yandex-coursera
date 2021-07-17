#include <algorithm>
#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

class Learner {
 private:
  set<string> dict; // Если не можем менять публичный интерфейс, меняем приватный)0)
                    // Да и слова сразу отсортированы будут
                    // И метод find можем использовать)0)

 public:
  int Learn(const vector<string>& words) {
    int newWords = 0;
    for (const auto& word : words) {
      if (dict.find(word) == dict.end()) {
        ++newWords;
        dict.insert(word);
      }
    }
    return newWords;
  }

  vector<string> KnownWords() {
    return {dict.begin(), dict.end()};
  }
};
int main()
{
    Learner learner;
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::vector<std::string> words;
        std::stringstream ss(line);
        std::string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        std::cout << learner.Learn(words) << "\n";
    }
    std::cout << "=== known words ===\n";

    for (auto word : learner.KnownWords())
    {
        std::cout << word << "\n";
    }
    return 0;
}