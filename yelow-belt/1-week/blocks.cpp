#include <iostream>

using namespace std;

int main(){
    int num = 0; cin>>num;
    short density = 0; cin>>density;
    uint64_t sum = 0;
    int64_t x, y, z;
    for(int i = 0; i<num; ++i){
        cin>>x;
        cin>>y;
        cin>>z;
        sum+=x*y*z;
    }
    sum*=density;
    cout<<sum<<endl;
}