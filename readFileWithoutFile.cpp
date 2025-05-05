#include <bits/stdc++.h>
using namespace std;

class InputAnalyzer {
private:
    int line;
    int word;
    int character;

public:
    InputAnalyzer() : line(0), word(0), character(0) {}

    void readAndAnalyze() {
        cout << "Enter text (type 'exit' alone on a line to finish input):" << endl;

        string input;
        while (true) {
            getline(cin, input);

            if (input == "exit")
                break;

            line++;  

            stringstream ss(input);
            string temp;
            while (ss >> temp) {
                word++;
            }

            for (char ch : input) {
                if (!isspace(ch)) {
                    character++;
                }
            }
        }
    }

    void showResult() const {
        cout << "\nAnalysis Result:" << endl;
        cout << "Total lines: " << line << endl;
        cout << "Total words: " << word << endl;
        cout << "Total characters (excluding spaces): " << character << endl;
    }
};

int main() {
    InputAnalyzer analyzer;
    analyzer.readAndAnalyze();
    analyzer.showResult();

    return 0;
}
