#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix){

    auto left = lower_bound(range_begin, range_end, prefix);
    string up_b = prefix;

    ++up_b[up_b.size() - 1];

    auto right = lower_bound(range_begin, range_end, up_b);
    
    return {left, right};
}

int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}