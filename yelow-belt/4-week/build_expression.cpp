#include <iostream>
#include <deque>

using namespace std;

//template<typename It>
void MakeParentheses(deque<string> &v){
    v.push_front("(");
    v.push_back(") ");
}


int main(){
    int x; // original expression
    cin>>x;

    int number_of_actions;
    cin>>number_of_actions;

    deque<string> expession;
    expession.push_back(to_string(x));

    string symbol_of_operation;
    int number;

    for(int i = 0; i<number_of_actions; ++i){
        MakeParentheses(expession);
        cin>>symbol_of_operation;
        cin>>number;
        expession.push_back(symbol_of_operation);
        expession.push_back(" ");
        expession.push_back(to_string(number));
    }

    for(const auto &c: expession){
        cout<<c;
    }

    return 0;
}