#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    int size = v.size(); //определим размер вектора
    vector<int> c = v; //создам копию
    for (auto i : c) { // в копии пройдусь от начала до конца
        v[size - 1] = i; // и буду вставлять значения в вектор v с конца
        size--;
    }
}
int main(){
    vector<int> nambers = { 5,4,3,1,2 };
    Reverse(nambers); //изменили вектор
    for (auto i : nambers) { // проверим как изменился вектор
        cout << i << " ";
    }
    return 0;
}
