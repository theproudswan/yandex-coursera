#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Состояние людей
* 1 - спокойный
* 2 - беспокоится


// Изначально была версия, где кол-во нервных подсчитывалось сразу
// она была эффективнее, но выдавала ошибку


*/

void PrintPeople(const vector<int>& people) {
  int i=0;
  for(auto a: people){
    cout<<i<<": "<<a<<endl;
    i++;
  }
}

int main(){
  vector<int> people;
  string action;
  int operations;
  cin>>operations;
  int buf;
  int anxious = 0;
  for (int i=0; i<operations; i++){
    cin>>action;
    if(action == "COME"){
      cin>>buf;
      if(buf>0){
            for(int j=0; j<buf; ++j){
                people.push_back(1);
            }
      } else {
          int k=people.size();
          int k1=people.size()+buf;
            for(auto j: people){
                if(k>k1){
                people.pop_back();
                k--;
                }
            }
      }

    } else if(action == "WORRY"){
      cin>>buf;
      people[buf]=2;
    } else if(action == "QUIET"){
      cin>>buf;
      people[buf]=1;
    } else if(action == "WORRY_COUNT"){
        int l=0;
        for(auto r: people){
            if(r==2){
                l++;
            }
        }
      cout<<l<<endl;
  } else if(action == "PRINT"){
      PrintPeople(people);
    }
  }

  return 0;
}
