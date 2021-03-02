#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s){
    vector<string> result;
    string tmp = "";
    auto iterator = s.begin();
    while (iterator < s.end()){
        auto it = find_if(iterator, s.end(),
        [](const auto &c){
            return c == ' ';
        });
        while(iterator!=it){
            tmp+=*iterator;
            ++iterator;
        }
        result.push_back(tmp);
        tmp = "";
        ++iterator;
    }
    return result;
}

int main() {
  string s = "C Cpp Java Python";
  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}