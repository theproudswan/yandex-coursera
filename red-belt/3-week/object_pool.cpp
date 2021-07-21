#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
#include <deque>

using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate(){
      if (released_objects.empty()){
          auto ptr = new T;
          allocated_objects.insert(ptr);
          return ptr;
      }
      auto ptr = released_objects.front();
      allocated_objects.insert(ptr);
      released_objects.pop_front();
      return ptr;

  }
  T* TryAllocate(){
      if (released_objects.empty()){
          return nullptr;
      }
      return Allocate();
  }

  void Deallocate(T* object){
      if (allocated_objects.find(object) == allocated_objects.end()){
            throw invalid_argument("");
      }
      released_objects.push_back(object);
      allocated_objects.erase(object);
  }

  ~ObjectPool(){
      for(auto i : allocated_objects){
          delete i;
      }
      for(auto i : released_objects){
          delete i;
      }
  }

private:
  // Добавьте сюда поля
  set<T*> allocated_objects; // Выделенные
  deque<T*> released_objects; // Освобожденные 
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
