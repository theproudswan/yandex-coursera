#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    ifstream input("input.txt");
    string line;
    int M=0, N=0;;
    input >> N >> M;
    input.ignore(1);
    if(input){
        for (int i = N; i > 0;--i) {
            for (int j = M; j > 1; --j) {
                getline(input, line, ',');
                cout << setw(10) << line << " ";
            }
            getline(input, line);
            cout << setw(10) << line << endl;
        }
    }

    return 0;

}
