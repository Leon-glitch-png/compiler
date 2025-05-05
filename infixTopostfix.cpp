#include <bits/stdc++.h>
using namespace std;

int precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }else if(ch == '^'){
            return 3;
    }else{
            return 0;
    }

}


bool isOperator(char ch){
    if(!isalpha(ch) && !isdigit(ch)){
        return true;
    }else{
        return false;
    }
}

string infixToPostfix(string infix){
    string postfix = "";
    stack<char> s;
    for(char ch:infix){
        if(isalpha(ch)|| isdigit(ch)){

            postfix += ch;

        }else if(ch == '('){
            s.push(ch);
        }else if(ch == ')'){
            while(!s.empty() && s.top() !='('){
                postfix +=s.top();
                s.pop();
            }
            s.pop();
        }else{
            while(!s.empty()&& precedence(s.top()) >= precedence(ch)){
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main(){
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}