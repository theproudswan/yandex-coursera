#include <iostream>
#include <vector>

using namespace std;

int main(){
  int a;
  cin>>a;
  vector <int> b;
  while(a!=1){
    b.push_back(a%2);
    a/=2;
  }
  b.push_back(1);
  for (auto i = b.rbegin(); i != b.rend(); ++i)
    {
        cout << *i ;
    }
  cout<<endl;
  return 0;
}
