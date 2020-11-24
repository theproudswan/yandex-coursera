#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    map<string, set<string>> vocabulary;
    int q; //количество оперций
    cin >> q;
    for (int i = 0; i < q; i++){
        string operation_name;
        cin >> operation_name;
        if (operation_name=="ADD"){
            string word1, word2;
            cin >> word1 >> word2;
            vocabulary[word1].insert(word2);
            vocabulary[word2].insert(word1);
        } else if (operation_name == "COUNT"){
            string word;
            cin >> word;
            cout << vocabulary[word].size() << endl;
        } else if (operation_name == "CHECK"){
            string check_word1, check_word2;
            cin >> check_word1 >> check_word2;
            if(vocabulary.count(check_word1) && vocabulary[check_word1].count(check_word2)){
                cout << "YES"<< endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
