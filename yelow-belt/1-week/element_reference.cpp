#include <iostream>
#include <map>
#include <exception>
#include <stdexcept>

using namespace std;

template <typename Key, typename Value, typename Find>
Value & GetRefStrict( map<Key, Value> &m, const Find &find){
    if (m.count(find) == 0) throw runtime_error("");
    return m[find];
}

int main(){
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}