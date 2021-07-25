#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector() {
    size = capacity = 0;
    data = nullptr;
  }
  explicit SimpleVector(size_t size_){
      capacity = size = size_;
      data = new T[size_];
  }
  ~SimpleVector(){
      delete[] data;
  }

  T& operator[](size_t index){
      return data[index];
  }

  T* begin(){
      return data;
  }
  T* end(){
      return data + size;
  }
  const T* begin() const {
      return data;
  }
  const T* end() const{
      return data + size;
  }
  size_t Size() const{
      return size;
  }
  size_t Capacity() const{
      return capacity;
  }
  void PushBack(const T& value){
    if(Capacity() == 0){
        T* temp = new T[++capacity]{value};
        ++size;
        data = temp;
    } else {
        if (Size() == Capacity()) {
            T *temp = new T[2 * capacity]{};
            capacity *= 2;

            for (size_t i = 0; i <= size; i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
        }
        data[size++] = value;
    }
  }

private:
  // Добавьте поля для хранения данных вектора
  size_t size = 0;
  size_t capacity = 0;
  T* data;
};
