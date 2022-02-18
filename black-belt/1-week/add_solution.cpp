#include <iostream>
#include <string>
#include <optional>
#include <limits>


using namespace std;

template <typename T>
optional<T> Sum(const T& a, const T& b){
    if (a > 0 && b > 0){
        if (min(a, b) > numeric_limits<T>::max() - max(a, b)){
            return nullopt;
        }
    } else if (a < 0 && b < 0){
        if (max(a, b) < numeric_limits<T>::min() - min(a, b)) {
            return nullopt;
        }
    }
    return a + b;
}


int main(){
    int64_t x, y;
    cin >> x >> y;
    if (auto sum = Sum(x, y)){
        cout << sum.value() << endl;
    } else {
        cout << "Overflow!" << endl;
    }
    return 0;
}
