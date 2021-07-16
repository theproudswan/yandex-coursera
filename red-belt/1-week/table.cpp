#include "test_runner.h"

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table{
public: 
    vector<T>& operator[] (size_t index){
        return matrix[index];
    }
    const vector<T>& operator[] (size_t index) const {
        return matrix[index];
    }
    Table (size_t _rows, size_t _columns){
        Resize(_rows, _columns);
    }
    void Resize (size_t _rows, size_t _columns){
        matrix.resize(_rows);
        for (auto& it : matrix){
            it.resize(_columns);
        }
    }
    pair<size_t, size_t> Size() const{
        if (!matrix.empty() && !matrix[0].empty())
            return make_pair(matrix.size(), matrix[0].size());
        return make_pair(0, 0);
    }
    
private:

vector<vector<T>> matrix;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
