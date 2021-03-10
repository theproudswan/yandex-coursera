#include <iostream>
#include <deque>

using namespace std;

// Можно использовать структуру для упрощения, но и так вполне удобно

//template<typename It>
void MakeParentheses(deque<string> &v){
    v.push_front("(");
    v.push_back(") ");
}

void NeedParentheses(deque<string> &v, const char &prev, const char &now){
    if(((prev == '-')||(prev == '+'))&&((now == '*')||(now == '/'))){
        MakeParentheses(v);
    } else {
        v.push_back(" ");
    }
}

int main(){
    int x; // original expression
    cin>>x;

    int number_of_actions;
    cin>>number_of_actions;

    deque<string> expession;
    expession.push_back(to_string(x));

    string symbol_of_operation = "", previous;
    int number;

    for(int i = 0; i<number_of_actions; ++i){
        //NeedParentheses(expession, previous, symbol_of_operation);
        previous = symbol_of_operation;
        cin>>symbol_of_operation;
        cin>>number;
        NeedParentheses(expession, previous[0], symbol_of_operation[0]);
        expession.push_back(symbol_of_operation);
        expession.push_back(" ");
        expession.push_back(to_string(number));
    }

    for(const auto &c: expession){
        cout<<c;
    }

    return 0;
}