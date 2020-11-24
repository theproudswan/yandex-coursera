#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> IsAnagramm(const string & word){
    map <char, int> result;

    for(const auto &letter: word){
        ++result[letter];
    }

    return result;
}

int main(){
    int n; // Кол-во пар
    cin>>n;
    string first_word, second_word;

    for (int i=0; i<n; ++i){
        cin>>first_word>>second_word;

        if(IsAnagramm(first_word)==IsAnagramm(second_word)){
            cout<< "YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}
