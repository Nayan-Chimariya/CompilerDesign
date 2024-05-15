#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class CodeGenerator
{
public:
    CodeGenerator() : tempCount(0), regCount(0) {}

    string generateIntermediate(const string &expr)
    {
        istringstream tokens(tokenize(expr));
        string token;
        vector<string> postfix;
        stack<string> opStack;

        while (tokens >> token)
        {
            if (isdigit(token[0]) || isalpha(token[0]))
                postfix.push_back(token);
            else if (token == "(")
                opStack.push(token);
            else if (token == ")")
            {
                while (!opStack.empty() && opStack.top() != "(")
                {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.pop();
            }
            else if (isOperator(token))
            {
                while (!opStack.empty() && precedence(opStack.top()) >= precedence(token) && opStack.top() != "(")
                {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(token);
            }
        }

        while (!opStack.empty())
        {
            postfix.push_back(opStack.top());
            opStack.pop();
        }

        vector<string> outputStack;
        for (const auto &elem : postfix)
        {
            if (isOperator(elem))
            {
                string op2 = outputStack.back();
                outputStack.pop_back();
                string op1 = outputStack.back();
                outputStack.pop_back();
                string temp = newTemp();
                cout << temp << " = " << op1 << " " << elem << " " << op2 << endl;
                outputStack.push_back(temp);
                tacCode.push_back({temp, op1, elem, op2});
            }
            else
                outputStack.push_back(elem);
        }

        return outputStack.back();
    }

    void generateMachineCode()
    {
        for (const auto &code : tacCode)
        {
            string reg1 = "R" + to_string(++regCount);
            string reg2 = "R" + to_string(++regCount);
            cout << "LOAD " << reg1 << ", " << code.op1 << endl;
            cout << "LOAD " << reg2 << ", " << code.op2 << endl;

            string op = code.op;
            if (op == "+")
                op = "ADD";
            else if (op == "-")
                op = "SUB";
            else if (op == "*")
                op = "MUL";
            else if (op == "/")
                op = "DIV";

            cout << op << " " << reg1 << ", " << reg1 << ", " << reg2 << endl;
            cout << "STORE " << code.result << ", " << reg1 << endl;
        }
    }

private:
    struct TacEntry
    {
        string result, op1, op, op2;
    };
    vector<TacEntry> tacCode;
    int tempCount;
    int regCount;

    bool isOperator(const string &token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int precedence(const string &op)
    {
        if (op == "*" || op == "/")
            return 2;
        if (op == "+" || op == "-")
            return 1;
        return 0;
    }

    string newTemp()
    {
        return "t" + to_string(++tempCount);
    }

    istringstream tokenize(const string &expr)
    {
        string tokens;
        for (char ch : expr)
        {
            if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                tokens += ' ';
                tokens += ch;
                tokens += ' ';
            }
            else
                tokens += ch;
        }
        return istringstream(tokens);
    }
};

int main()
{
    CodeGenerator cg;
    string expression;

    cout << "Enter an expression (e.g., (a - b) * (c + d)): ";
    getline(cin, expression);

    cout << "\nIntermediate Code Generation for the expression: \n"
         << expression << endl;
    cg.generateIntermediate(expression);

    cout << "\nMachine Code Generation: \n"
         << endl;
    cg.generateMachineCode();
    return 0;
}
