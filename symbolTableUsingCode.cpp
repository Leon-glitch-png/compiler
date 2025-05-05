#include <bits/stdc++.h>
using namespace std;

bool isKeyword(string str)
{
    string keywords[] = {"for", "while", "do", "if", "class", "else", "else if", "public", "private", "protected", "static", "void", "int", "float", "double", "import", "char", "string", "boolean", "break", "switch", "case", "continue", "default", "long", "new", "return", "short"};
    for (string keyword : keywords)
    {
        if (str == keyword)
            return true;
    }
    return false;
}

bool isSpecialSymbol(char ch)
{
    string specialSymbols = "'\"{}();,[]";
    return specialSymbols.find(ch) != string::npos;
}

bool isOperator(string str)
{
    string operators[] = {"+", "-", "=", "&&", "", "/", "++", "--", "||", "!", "^", "%", "==", "~", ">", "<", ">=", "<=", "+=", "-=", "=", "/=", "%="};
    for (string op : operators)
    {
        if (op == str)
            return true;
    }
    return false;
}

bool isIdentifier(string str)
{
    if (isdigit(str[0]))
        return false;
    for (char ch : str)
    {
        if (!isalnum(ch) && ch != '_')
            return false;
    }
    return true;
}

string cleanVariableName(string varName)
{
    while (!varName.empty() && (varName.back() == ';' || varName.back() == '='))
    {
        varName.pop_back();
    }
    return varName;
}

int main()
{
    vector<string> var, varType, scope;
    vector<string> code;
    string input;
    cout << "Enter the code (type 'end' to finish input):" << endl;
    while (true)
    {
        getline(cin, input);
        if (input == "end")
            break;
        code.push_back(input);
    }

    vector<string> dataTypes = {"int", "float", "double", "short", "string", "char", "boolean", "void", "long"};
    int scopeLevel = 0;

    for (string line : code)
    {
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            if (word == "{")
                scopeLevel++;
            else if (word == "}")
                scopeLevel--;
            else
            {
                for (string type : dataTypes)
                {
                    if (word == type)
                    {
                        string varName;
                        if (iss >> varName)
                        {
                            varName = cleanVariableName(varName);
                            if (isIdentifier(varName))
                            {
                                var.push_back(varName);
                                varType.push_back(word);
                                scope.push_back(scopeLevel == 0 ? "Global" : "Local");
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    cout << "\nSymbol Table:\n";
    cout << "Variable\tType\tScope" << endl;
    for (size_t i = 0; i < var.size(); i++)
    {
        cout << var[i] << "\t" << varType[i] << "\t" << scope[i] << endl;
    }
    return 0;
}