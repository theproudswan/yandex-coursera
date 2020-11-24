#include <iostream>
#include <cmath>

using namespace std;

int main(){

  float a,b,c,d;
  cin>>a>>b>>c;
  d=sqrt(pow(b, 2)-4*a*c);
  if (a==0){
    if (b!=0)
      cout<<-c/b<<endl;
  } else {
    if(d>0){
      if(a!=0)
       cout << (-b - d)/(2*a)<<" "<<(-b + d)/(2*a)<<endl;
    } else if (d==0){
      if (a!=0)
       cout << (-b - d)/(2*a)<<endl;
    }
  }


  return 0;
}
