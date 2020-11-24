#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    string line;
    if(input){
        while(getline(input, line)){
            cout<<line<<endl;
        }
    } else {
        cout <<"\nCOULD NOT OPEN\n";
    }

    return 0;
}
