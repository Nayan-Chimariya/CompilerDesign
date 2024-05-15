#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a character is a valid identifier character
bool isIdentifierChar(char c)
{
    return isalnum(c) || c == '_';
}

// Function to check if a string is a keyword
bool isKeyword(string str)
{
    string keywords[] = {"if", "else", "while", "for", "int", "float", "return", "main"};
    for (const auto &keyword : keywords)
    {
        if (str == keyword)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string input;
    cout << "Enter input string: ";
    getline(cin, input);

    string token = "";
    for (char c : input)
    {
        if (isIdentifierChar(c))
        {
            // Build identifier token
            token += c;
        }
        else
        {
            // Process token
            if (!token.empty())
            {
                if (isKeyword(token))
                {
                    cout << "Keyword: " << token << endl;
                }
                else
                {
                    cout << "Identifier: " << token << endl;
                }
                token = "";
            }
            // Process special characters
            cout << "Special Character: " << c << endl;
        }
    }

    // Process last token
    if (!token.empty())
    {
        if (isKeyword(token))
        {
            cout << "Keyword: " << token << endl;
        }
        else
        {
            cout << "Identifier: " << token << endl;
        }
    }

    return 0;
}
