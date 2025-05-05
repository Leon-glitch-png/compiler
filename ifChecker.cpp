
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

bool check(string stm)
{
    int n = stm.length();
    if (stm[0] != 'i' || stm[1] != 'f' || stm[2] != '(' || stm[n - 1] != ')')
    {
        return false;
    }

   
    
    string temp;
    int cnt = 0;
    for (int i = 3; i < n - 1; i++)
    {
        if ((stm[i] == '=' || stm[i] == '!' || stm[i] == '>' || stm[i] == '<') && cnt == 0)
        {
            if (!isValid(temp))
            {
                return false;
            }
            temp = "";
            i++;
            if (i >= n - 1)
            {
                return false;
            }
            else if (isalnum(stm[i]))
            {
                temp.push_back(stm[i]);
            }
            else if (stm[i] != '=')
            {
                return false;
            }
            cnt++;
        }
        else
        {
             if (!isDigit(stm[i]) && !isSymbol(stm[i]) && stm[i] != '(' && stm[i] != ')') {
                return false; 
            }
            temp.push_back(stm[i]);
        }
    }
    return isValid(temp);
}

int main()
{
    string stm;
    cout<<"Enter the expression: ";
    getline(cin, stm);
    if (check(stm))
    {
        cout << "Yes The statement is valid" << endl;
    }
    else
    {
        cout << "No The statement is Invalid" << endl;
    }
}
