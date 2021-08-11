#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  // Напишите реализацию функции,
  // не копируя сортируемые элементы
  using type = typename RandomIt::value_type;
  if(distance(range_begin, range_end) < 2){
      return;
  }
  vector<type> v(make_move_iterator(range_begin), make_move_iterator(range_end));

  auto first_part_it = v.begin() + v.size()/3;
  auto second_part_it = first_part_it + v.size()/3;

  MergeSort((v.begin()), (first_part_it));
  MergeSort((first_part_it), (second_part_it));
  MergeSort((second_part_it), (v.end()));
  
  vector<type> tmp;

  merge(make_move_iterator(v.begin()), make_move_iterator(first_part_it), 
        make_move_iterator(first_part_it), make_move_iterator(second_part_it),
        move(back_inserter(tmp)));

  merge(make_move_iterator(tmp.begin()), make_move_iterator(tmp.end()),
        make_move_iterator(second_part_it), make_move_iterator(v.end()), 
        range_begin);
   
}

void TestIntVector() {
  vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
  MergeSort(begin(numbers), end(numbers));
  ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestIntVector);
  return 0;
}
