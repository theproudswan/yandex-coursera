#include <iostream>

using namespace std;

int Factorial(int x){
  if (x <= 1) {
    return 1;
  } else {
    return x * Factorial(x - 1);  // вычисляем факториал от x-1 и умножаем на x
  }
}

int main(){
  int x;
  cin>>x;
  Factorial(x);
  return 0;
}
