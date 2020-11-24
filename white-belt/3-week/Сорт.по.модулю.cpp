#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    int buf;
    for(n; n>0; n--){
        cin>>buf;
        v.push_back(buf);
    }

    sort(v.begin(), v.end(), [](const int& x, const int& y){ return abs(x) < abs(y); });

    for(const auto& i: v){
        cout<<i<<' ';
    }

    return 0;
}
