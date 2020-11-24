#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    ifstream input("input.txt");
    string line;
    cout<<fixed<<setprecision(3);
    if(input){
        while(getline(input, line)){
            double dline = atof(line.c_str());
            cout<<dline<<endl;
        }
    }

    return 0;
}
