#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
    auto it = find_if(elements.begin(), elements.end(),
    [&border](const T &num){
        return num > border;
    });
    vector<T> result;
    for(it; it!=elements.end(); ++it){
        result.push_back(*it);
    }
    return result;
}

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
