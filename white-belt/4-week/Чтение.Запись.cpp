#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    string line;
    if(input&&output){
        while(getline(input, line)){
            output << line << endl;
        }
    } else {
        cout <<"\nCOULD NOT OPEN\n";
    }

    return 0;
}
