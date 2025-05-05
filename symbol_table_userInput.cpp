#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of variables: ";
    cin >> n;
    cin.ignore();

    vector<string> variableNames;
    vector<string> dataTypes;

    string types[] = {"byte", "short", "int", "long", "float", "double", "char", "boolean", "string"};

    while (n > 0)
    {
        string name;
        while (true)
        {
            cout << "Enter variable name: ";
            getline(cin, name);

            bool isValid = true;

            if (name.empty() || isdigit(name[0]))
            {
                isValid = false;
            }

            for (char ch : name)
            {
                if (!(isalnum(ch) || ch == '_'))
                {
                    isValid = false;
                    break;
                }
            }

            if (!isValid)
            {
                cout << "Invalid variable name! Please enter a valid name." << endl;
            }
            else
            {
                break;
            }
        }

        string type;
        while (true)
        {
            cout << "Enter data type: ";
            getline(cin, type);

            bool isValid = false;
            for ( string &t : types)
            {
                if (t == type)
                {
                    isValid = true;
                    break;
                }
            }

            if (!isValid)
            {
                cout << "Invalid data type! Please enter a valid cpp data type." << endl;
            }
            else
            {
                break;
            }
        }

        variableNames.push_back(name);
        dataTypes.push_back(type);
        n--;
    }

    cout << "\nSymbol Table:" << endl;
    cout << "S NO.  |  Variable Name  |  Data Type" << endl;
    cout << "-------------------------------------" << endl;

    for (size_t i = 0; i < variableNames.size(); i++)
    {
        printf("%-6zu | %-15s | %7s\n", i + 1, variableNames[i].c_str(), dataTypes[i].c_str());
        cout << "-------------------------------------" << endl;
    }

    return 0;
}
