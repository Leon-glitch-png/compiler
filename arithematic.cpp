

#include <bits/stdc++.h>
using namespace std;


string removeSpace(string str) {
    string res = "";
    for (char ch : str) {
        if (!isspace(ch)) {
            res += ch;
        }
    }
    return res;
}

bool isDigit(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
        return true;
    } else {
        return false;
    }
}

bool isSymbol(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    } else {
        return false;
    }
}

bool isValid(string str) {
    if (str.empty()) {
        return false;
    }


    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ')') {
            cnt--;
        } else if (str[i] == '(') {
            cnt++;
        }
        if (cnt < 0) {
            return false;
        }
    }
    if (cnt != 0) {
        return false;
    }

    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == '(' && str[i + 1] == ')') {
            return false;
        }
    }

    if (!isDigit(str[0]) && str[0] != '(') {
        return false;
    }
    if (!isDigit(str[str.length() - 1]) && str[str.length() - 1] != ')') {
        return false;
    }

    for (int i = 1; i < str.length(); i++) {
        if (isSymbol(str[i]) && isSymbol(str[i - 1])) {
            return false;
        }
        if (str[i - 1] == '(' && isSymbol(str[i])) {
            return false;
        }
        if (str[i] == ')' && isSymbol(str[i - 1])) {
            return false;
        }
    }

   

    return true;
}

int main() {
    string str;
    cout << "Enter the arithmetic expression: ";
    getline(cin, str);
    str = removeSpace(str);
    if (isValid(str)) {
        cout << "The expression is Valid" << endl;
    } else {
        cout << "The expression is Invalid" << endl;
    }
}