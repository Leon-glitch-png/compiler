#include <bits/stdc++.h>
using namespace std;
bool matchExpression(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string removeSpace(string str)
{
    string ans = "";
    for (char ch : str)
    {
        if (isspace(ch))
        {
            continue;
        }
        else
        {
            ans += ch;
        }
    }
    return ans;
}
bool isValid(string str)
{

    str = removeSpace(str);

    int n = str.length();
    if (n == 0)
    {
        return false;
    }

    if (str[0] == '*' || str[0] == '/' || str[0] == '^' || str[n - 1] == '*' || str[n - 1] == '/' || str[n - 1] == '^' || str[n - 1] == '-' || str[n - 1] == '+')
    {
        return false;
    }
    for (int i = 0; i < n - 1; i++)
    {

        if (isdigit(str[i]))
        {
            continue;
        }
        if (matchExpression(str[i]) && matchExpression(str[i + 1]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    if (isValid(str))
    {
        cout << "Valid Expression" << endl;
    }
    else
    {
        cout << "Invalid Expression" << endl;
    }
    return 0;
}