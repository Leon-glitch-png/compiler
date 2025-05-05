/* 
time complexity 
*/
#include <bits/stdc++.h>
using namespace std;
class Table
{

private:
    vector<vector<string>> table;

public:
    Table()
    {
        table.push_back({"Sr.no", "variable name", "data type "});
    }
    void addData(vector<string> data)
    {

        int row = data.size();
        int col = data[0].size();
        table.push_back(data);
    }

    void printTable()
    {
        vector<int> len;
        for (int i = 0; i < table[0].size(); i++)
        {
            len.push_back(table[0][i].size());
        }

        for (int i = 0; i < table.size(); i++)
        {
            for (int j = 0; j < table[i].size(); j++)
            {
                cout << table[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

void solve()
{
}

int main()
{

    Table table;
    table.addData({"1", "name", "string"});
    table.addData({"2", "name", "string"});
    table.addData({"3", "name", "string"});
    table.addData({"4", "name", "string"});
    table.addData({"5", "name", "string"});
    table.addData({"6", "name", "string"});
    table.addData({"7", "name", "string"});
    table.printTable();
    return 0;
}