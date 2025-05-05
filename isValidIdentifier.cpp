#include<bits/stdc++.h>

using namespace std;

unordered_set<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "inline", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while", "class", "namespace", "private", "public", "protected"
};

bool isValidVariable(const string& str) {
    if (str.empty()){
        return false;
    };  

    if (isdigit(str[0])) {
        return false;
    } 

    if (keywords.count(str)){ 
        return false;
    } 

    for (char ch : str) {
        if (!(isalnum(ch) || ch == '_')) {
            return false;  
        }
    }

    return true;
}

int main() {
    string varName;
    cout << "Enter a variable name: ";
    cin >> varName;

    if (isValidVariable(varName)) {
        cout << "\"" << varName << "\" is a valid C++ variable name.\n";
    } else {
        cout << "\"" << varName << "\" is NOT a valid C++ variable name.\n";
    }

    return 0;
}
