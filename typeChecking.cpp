// /*
// Date:02/04/2025

// Aim:Write a C program to implement type checking

// */

// #include <bits/stdc++.h>
// using namespace std;
// bool isIdentifier(string str)
// {
//     if (isdigit(str[0]))
//         return false;
//     for (char ch : str)
//     {
//         if (!isalnum(ch) && ch != '_')
//             return false;
//     }
//     return true;
// }

// string cleanVariableName(string varName)
// {
//     while (!varName.empty() && (varName.back() == ';' || varName.back() == '='))
//     {
//         varName.pop_back();
//     }
//     return varName;
// }

// void process()
// {
//     vector<string> var, varType, scope;
//     vector<string> code;
//     string input;
//     cout << "Enter the code (type 'end' to querry to know type of variable):" << endl;
//     while (true)
//     {
//         getline(cin, input);
//         if (input == "end")
//             break;
//         code.push_back(input);
//     }

//     vector<string> dataTypes = {"int", "float", "double", "short", "string", "char", "boolean", "void", "long"};
//     int scopeLevel = 0;

//     for (string line : code)
//     {
//         istringstream iss(line);
//         string word;
//         while (iss >> word)
//         {
//             if (word == "{")
//                 scopeLevel++;
//             else if (word == "}")
//                 scopeLevel--;
//             else
//             {
//                 for (string type : dataTypes)
//                 {
//                     if (word == type)
//                     {
//                         string varName;
//                         if (iss >> varName)
//                         {
//                             varName = cleanVariableName(varName);
//                             if (isIdentifier(varName))
//                             {
//                                 var.push_back(varName);
//                                 varType.push_back(word);
//                                 scope.push_back(scopeLevel == 0 ? "Global" : "Local");
//                             }
//                         }
//                         break;
//                     }
//                 }
//             }
//         }
//     }

//     bool flage = true;
//     while (flage)
//     {
//         string variable;
//         cout << "Enter the variable name or type end to exit: ";
//         cin >> variable;
//         if (variable == "end")
//         {
//             flage = false;
//             return;
//         }

//         bool found = false;
//         for (int i = 0; i < var.size(); i++)
//         {
//             if (var[i] == variable)
//             {

//                 cout << variable << " : type is " << varType[i] << endl;
//                 found = true;
//             }
//         }

//         if (!found)
//         {
//             cout << "Variable not found " << endl;
//         }
//     }
// }

// int main()
// {
//     process();
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of variables" << endl;
    cin >> n;
    cin.ignore();

    unordered_map<string, string> var;
    for (int i = 0; i < n; ++i)
    {
        string name, datatype;
        cout << "Enter name of the variable " << (i + 1) << endl;
        getline(cin, name);
        cout << "Enter datatype of the variable " << (i + 1) << endl;
        getline(cin, datatype);
        var[name] = datatype;
    }

    cout << "Enter an expression" << endl;
    string exp;
    getline(cin, exp);
    exp += " ";

    string s = "";
    string datatype = "";
    bool breakvar = false;

    for (char ch : exp)
    {
        if (isalnum(ch) || ch == '_')
        {
            s += ch;
        }
        else
        {
            if (s.empty())
                continue;

            if (var.find(s) == var.end())
            {
                cout << s << " Variable not found" << endl;
                breakvar = true;
                break;
            }

            if (datatype.empty())
            {
                datatype = var[s];
            }
            else
            {
                if (datatype != var[s])
                {
                    cout << "The data types are different" << endl;
                    breakvar = true;
                    break;
                }
            }
            s = "";
        }
    }

    if (!breakvar)
    {
        cout << "The final datatype is " << datatype << endl;
    }

    return 0;
}
