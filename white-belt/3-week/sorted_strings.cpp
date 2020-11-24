#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    strings.push_back(s); //добавим строку
  }
  vector<string> GetSortedStrings() {
    sort(begin(strings), end(strings)); //отсортируем вектор строк
    return strings; //и вернем вектор
  }
private:
  vector<string> strings; //так будут строки храниться
};
