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
                i++;
            }
            printf("Identifier: ");
        }
        // Constants
        else if (isDigit(input[i]))
        {
            while (isDigit(input[i]))
            {
                i++;
            }
            printf("Constant: ");
        }
        // Operators
        else if (isOperator(input[i]))
        {
            // Handle multi-character operators
            if (input[i] == '&' && input[i + 1] == '&')
            {
                printf("Operator: &&");
                i += 2;
            }
            else if (input[i] == '|' && input[i + 1] == '|')
            {
                printf("Operator: ||");
                i += 2;
            }
            else
            {
                printf("Operator: %c", input[i]);
                i++;
            }
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
            printf("Unknown character: %c\n", input[i]);
            return;
        }

        // Print the recognized token
        for (int j = 0; j <= i - 1 && !isspace(input[j]); j++)
        {
            printf("%c", input[j]);
        }
        printf("\n");
    }
}

int main()
{
    char input[100];
    printf("Enter input string: ");
    scanf("%s", input);
    recognize(input);
    return 0;
}