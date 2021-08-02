#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    unsigned athlets_count;
    cin >> athlets_count;
    list<unsigned> athlets;
    unsigned athlets_number;
    unsigned athlets_position;
    while(athlets_count){
        cin >> athlets_number;
        cin >> athlets_position;
        auto it = find(begin(athlets), end(athlets), athlets_position);
        if(it == end(athlets)){
            athlets.push_back(athlets_number);
        } else {
            athlets.insert((it), athlets_number);
        }
        athlets_count--;
    }
    for(auto i : athlets){
        cout << i << '\n';
    }
    return 0;
}