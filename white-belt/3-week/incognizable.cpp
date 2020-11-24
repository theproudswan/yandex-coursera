#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Incognizable{
public:
    Incognizable() {}
    Incognizable(int a1) {
        v.push_back(a1);
    }
    Incognizable(int a1, int a2) {
        v.push_back(a1);
        v.push_back(a2);
    }
private:
    vector<int> v;
};
