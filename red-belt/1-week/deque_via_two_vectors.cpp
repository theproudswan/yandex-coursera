#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T>
class Deque{
public:
    Deque() = default;
    bool Empty() const {
        return (size1 + size2) == 0;
    }
    size_t Size() const {
        return size1 + size2;
    }
    T& operator[](size_t index){
        if(index < v_begin.size())                 
            return v_begin[size1 - index - 1];
        else                                        
            return v_end[index - v_begin.size()];   
    }
    const T& operator[](size_t index) const {
        if(index < v_begin.size())                 
            return v_begin[size1 - index - 1];
        else                                        
            return v_end[index - v_begin.size()];   
    }
    T& At(size_t index){
        if(index > (size1 + size2)){
            throw out_of_range("out_of_range");
        }
        if(index < v_begin.size())                 
            return v_begin[size1 - index - 1];              
        else                                        
            return v_end[index - v_begin.size()];   
    }
    const T& At(size_t index) const {
        if(index > (size1 + size2)){
            throw out_of_range("out_of_range");
        }
        if(index < v_begin.size())                 
            return v_begin[size1 - index - 1];             
        else                                        
            return v_end[index - v_begin.size()];   
    }
    const T& Front() const {
        return v_begin[size1-1];
    }
    const T& Back() const {
        return v_end[v_end.size() - 1];
    }
    T& Front() {
        if(size1 == 0){
            return v_end[0];
        }
        return v_begin[size1-1];
    }
    T& Back() {
        if(size2 == 0){
            return v_begin[0];
        }
        return v_end[size2 - 1];
    }
    void PushFront(const T& el){
        v_begin.push_back(el);
        size1++;
    }
    void PushBack(const T& el){
        v_end.push_back(el);
        size2++;
    }
    
private: 
    size_t size1 = 0;
    size_t size2 = 0;
    vector<T> v_begin;
    vector<T> v_end;
};


int main()
{
   
    return 0;
}