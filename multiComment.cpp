/*


Program to Check for un terminated, multi line comment statements in C program

Date:9/4/25

 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> code;
    string line;
    cout << "Enter the code and enter end at last " << endl;

    while (true)
    {
        getline(cin, line);
        if (line == "end")
            break;
        code.push_back(line);
    }

    int c = 0;

    for (const string &line : code)
    {
        for (size_t j = 0; j < line.length(); ++j)
        {
            if (line[j] == '/')
            {
                if (j + 1 < line.length() && line[j + 1] == '*')
                {
                    c++;
                    j++;
                }
            }
            else if (line[j] == '*')
            {
                if (j + 1 < line.length() && line[j + 1] == '/')
                {
                    c--;
                    j++;
                }
            }
        }
    }

    if (c == 0)
        cout << "no unterminated comments found" << endl;
    else
        cout << "there is a unterminated comment" << endl;

    return 0;
}
