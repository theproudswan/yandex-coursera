#include <iostream>
#include <set>

using namespace std;

int main(){
    set <string> words;
    string word;
    int N;
    cin>>N;
    for(N;N>0;N--){
        cin>>word;
        words.insert(word);
    }
    cout<<words.size()<<endl;

    return 0;
}
