#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  cin >> s;
  int k,p=-2,j=0;
  for(int i=0; i<s.length(); i++){
    if(s[i]=='f'){
      j++;
      if(j==2){
        k=i;
        break;
      }
    }
  }
  if(j==0){
    cout<<"-2"<<endl;
  } else if(j==1){
    cout<<-1<<endl;
  } else {
    cout<<k<<endl;
  }
  return 0;
}
