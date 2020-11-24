#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> result;
  for (auto [number, word]: m){
      result.insert(word);
  }

  return result;
}
/*
int main(){
    set<string> values = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (const string& value : values) {
      cout << value << endl;
    }

    return 0;
}
*/
