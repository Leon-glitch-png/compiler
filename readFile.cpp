/*
Date:16-04-2025
Aim: write a program in cpp to scan and count the number of character , words, line, in a file
*/

#include <bits/stdc++.h>
using namespace std;
class ReadFile
{
private:
    string fileName;
    int line;
    int word;
    int character;

public:
    ReadFile() : line(0), word(0), character(0) {}

public:
    void createAndWrite()
    {

        try
        {

            cout << "Enter the file name: ";
            getline(cin, this->fileName);
            if (fileName.empty())
            {

                throw runtime_error("File must contain name!");
            }

            ifstream file(this->fileName);

            if (file)
            {

                throw runtime_error("File name is already exist");
            }

            ofstream outFile(fileName);

            cout << "Enter the content of file: " << endl;
            std::cout << "Enter text to write to the file (type 'exit' to finish): " << endl;

            std::string input;
            while (true)
            {
                std::getline(std::cin, input);

                if (input == "exit")
                {
                    break;
                }

                outFile << input << endl;
            }

            outFile.close();
        }
        catch (const runtime_error &e)
        {
            cout << "Caught runtime error: " << e.what() << endl;
        }
        catch (...)
        {

            cout << "Caught an unknown exception!" << endl;
        }
    }

public:
    void countLine()
    {
        try
        {
            ifstream file(this->fileName);
            if (!file)
            {
                throw runtime_error("file does not exits !");
            }
            string line;

            while (getline(file, line))
            {
                this->line++;
            }

            cout << "Total number of line in file " << this->fileName << " is " << this->line << endl;
            file.close();
        }
        catch (const runtime_error &e)
        {
            cout << "Caught runtime error: " << e.what() << endl;
        }
        catch (...)
        {
            cout << "Caught an unknown exception!" << endl;
        }
    }

public:
    void countWord()
    {
        try
        {
            ifstream file(this->fileName);
            if (!file)
            {
                throw runtime_error("file does not exits !");
            }
            string word;

            while (file >> word)
            {
                this->word++;
            }

            cout << "Total number of word in file " << this->fileName << " is " << this->word << endl;
            file.close();
        }
        catch (const runtime_error &e)
        {
            cout << "Caught runtime error: " << e.what() << endl;
            return;
        }
        catch (...)
        {
            cout << "Caught an unknown exception!" << endl;
            return;
        }
    }

public:
    void countChar()
    {
        try
        {
            ifstream file(this->fileName);
            if (!file)
            {
                throw runtime_error("file does not exits !");
            }
            char ch;

            while (file.get(ch))
            {
                if (isspace(ch))
                {
                    continue;
                }
                this->character++;
            }

            cout << "Total number of character in file " << this->fileName << " is " << this->character << endl;
            file.close();
        }
        catch (const runtime_error &e)
        {
            cout << "Caught runtime error: " << e.what() << endl;
        }
        catch (...)
        {
            cout << "Caught an unknown exception!" << endl;
        }
    }
};


int main()
{

    ReadFile file;
    file.createAndWrite();
    file.countLine();
    file.countWord();
    file.countChar();

  
    return 0;
}