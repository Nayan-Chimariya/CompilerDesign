#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a letter
bool isLetter(char ch)
{
    return isalpha(ch) || ch == '_';
}

// Function to check if a character is a digit
bool isDigit(char ch)
{
    return isdigit(ch);
}

// Function to check if a character is an operator
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' || ch == '&' || ch == '|');
}

// Function to recognize identifiers, constants, and operators
void recognize(char input[])
{
    int len = strlen(input);
    int i = 0;
    while (i < len)
    {
        // Identifiers
        if (isLetter(input[i]))
        {
            while (isLetter(input[i]) || isDigit(input[i]))
            {
                printf("%c", input[i]);
                i++;
            }
            printf(": Identifier\n");
        }
        // Constants
        else if (isDigit(input[i]))
        {
            while (isDigit(input[i]))
            {
                printf("%c", input[i]);
                i++;
            }
            printf(": Constant\n");
        }
        // Operators
        else if (isOperator(input[i]))
        {
            printf("%c", input[i]);
            printf(": Operator\n");
            i++;
        }
        // Skip whitespace
        else if (isspace(input[i]))
        {
            i++;
            continue;
        }
        // Unknown character
        else
        {
            printf("%c: Unknown character\n", input[i]);
            return;
        }
    }
}

int main()
{
    char input[100];
    printf("Enter input string: ");
    scanf("%s", input);
    printf("Token: Type\n");
    recognize(input);
    return 0;
}
