#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string s){
  bool f=false;
  if(s.length()<=1){
    return true;
  } else{
    for(int i=0, j=s.length()-1; i<s.length()/2; ++i, --j){
      if(s[i]==s[j]){
        f=true;
      } else{
        return false;
      }
    }
    return f;
  }
}

int main(){
  string s;
  cin>>s;
  IsPalindrom(s);
  return 0;
}
