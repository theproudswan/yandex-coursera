#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> temperatures(n);
  int64_t sum = 0;
  for (int& temperature : temperatures) {
    cin >> temperature;
    sum += temperature;
  }

  int average = sum / n;

  vector<int> above_average_indices;
  for (int i = 0; i < n; ++i) {
    if (temperatures[i] > average) {
      above_average_indices.push_back(i);
    }
  }

  cout << above_average_indices.size() << endl;
  for (int i : above_average_indices) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
















/*
int main(){
    int n = 0; // number of days
    cin>>n;
    vector <int> v(n);
    vector <int> days;
    int64_t avg = 0;

    for (int i = 0; i<n; ++i){ // filling
        cin>>v[i];
    }
    avg = accumulate(v.begin(), v.end(), int())/v.size(); // we found the average

    for(int i = 0; i<n; ++i){
        if (v[i]>avg) days.push_back(i);
    }

    cout<<days.size()<<endl;
    for(int x: days){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}
*/