#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  int buf;
  vector<int> temperature;
  for(int i=0; i<n;++i){
    cin>>buf;
    temperature.push_back(buf);
  }
  int average;
  buf=0;
  for(int i=0; i<n; ++i){
    buf+=temperature[i];
  }
  average=buf/n;
  buf=0;
  vector<int> number_day;
  int k=0;
  for(auto s:temperature){
    if(s>average){
      buf++;
      number_day.push_back(k);
    }
    k++;
  }
  cout<<buf<<endl;
  for (auto s:number_day){
    cout<<s<<" ";
  }
  return 0;
}
