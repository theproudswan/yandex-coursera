#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s){
  bool f=false;
  for(int i=0, j=s.length()-1; i<s.length()/2; ++i, --j){
        if(s[i]==s[j]){
          f=true;
        } else{
          return false;
        }
      }
      return f;
}

vector <string> PalindromFilter(vector <string> s, int x){
  vector <string> ans;
  bool f=false;
  for(auto w: s){
    if (w.length()>= x){
      if(IsPalindrom(w)==1){
        ans.push_back(w);
      }
    }
  }
  return ans;
}

int main(){
  vector<string> s = {"one", "ono", "abacaba"};
  int x;
  cin>>x;
  PalindromFilter(s,x);
  return 0;
}
