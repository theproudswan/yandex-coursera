#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
string to_low(const string& s) { //перевод строки в нижний регистр
    string result;
    for (auto i : s) { //все буквы
        result += tolower(i); //вставляем в новую строку в нижнем регистре
    }
    return result; //возвращаем новую строку в нижнем регистре
}
bool str(string x, string y) {
    return to_low(x) < to_low(y);
}

int main(){
    vector <string> v;
    int n;
    cin>>n;
    string buf;
    for(n; n>0; --n){
        cin>>buf;
        v.push_back(buf);
    }
    sort(v.begin(), v.end(), str);

    for (const auto& i: v){
        cout<<i<<' ';
    }
    return 0;
}
