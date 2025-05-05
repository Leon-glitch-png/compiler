
/*
Date:19-03-2025
Write a program to check the tokens
*/

#include <bits/stdc++.h>

using namespace std;

unordered_set<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "inline", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while", "class", "namespace", "private", "public", "protected"
};

unordered_set<string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "++", "--"
};

unordered_set<char> specialSymbols = {
    ';', '(', ')', '{', '}', '[', ']', ','
};

bool isValidVariable(const string &str) {
    if (str.empty() || isdigit(str[0]) || keywords.count(str)) {
        return false;
    }
    for (char ch : str) {
        if (!(isalnum(ch) || ch == '_')) {
            return false;
        }
    }
    return true;
}

bool isNumber(const string &str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

void tokenize(string code) {
    vector<string> tokens;
    string token = "";
    
    for (size_t i = 0; i < code.length(); i++) {
        char ch = code[i];
        
        if (isspace(ch) || specialSymbols.count(ch)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token = "";
            }
            if (specialSymbols.count(ch)) {
                tokens.push_back(string(1, ch));
            }
        } else if (i + 1 < code.length() && operators.count(string(1, ch) + code[i + 1])) {
            if (!token.empty()) {
                tokens.push_back(token);
                token = "";
            }
            tokens.push_back(string(1, ch) + code[i + 1]);
            i++;
        } else if (operators.count(string(1, ch))) {
            if (!token.empty()) {
                tokens.push_back(token);
                token = "";
            }
            tokens.push_back(string(1, ch));
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }

    for (const string &t : tokens) {
        if (keywords.count(t)) {
            cout << t << " : Keyword" << endl;
        } else if (operators.count(t)) {
            cout << t << " : Operator" << endl;
        } else if (isNumber(t)) {
            cout << t << " : Number" << endl;
        } else if (isValidVariable(t)) {
            cout << t << " : Identifier" << endl;
        } else if (t.size() == 1 && specialSymbols.count(t[0])) {
            cout << t << " : Special Symbol" << endl;
        } else {
            cout << t << " : Unknown Token" << endl;
        }
    }
}

int main() {
    string code;

    cout << "Enter a code snippet: ";
    getline(cin, code);

    cout << "\nTokens Found:\n";
    tokenize(code);

    return 0;
}
