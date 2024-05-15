#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Function to compute FIRST set
unordered_map<char, unordered_set<char>> computeFirstSet(const unordered_map<char, vector<string>> &productions)
{
    unordered_map<char, unordered_set<char>> firstSet;
    for (auto const &[variable, expressions] : productions)
    {
        for (const auto &expression : expressions)
        {
            char firstSymbol = expression[0];
            if (!isupper(firstSymbol) || expression.empty())
            {
                firstSet[variable].insert(firstSymbol);
            }
            else
            {
                if (firstSet.find(firstSymbol) != firstSet.end())
                {
                    firstSet[variable].insert(firstSet[firstSymbol].begin(), firstSet[firstSymbol].end());
                }
            }
        }
    }
    return firstSet;
}

// Function to compute FOLLOW set
unordered_map<char, unordered_set<char>> computeFollowSet(const unordered_map<char, vector<string>> &productions, char startSymbol)
{
    unordered_map<char, unordered_set<char>> followSet;
    followSet[startSymbol].insert('$');

    bool changed = true;
    while (changed)
    {
        changed = false;
        for (const auto &[variable, expressions] : productions)
        {
            for (const auto &expression : expressions)
            {
                for (size_t i = 0; i < expression.size(); ++i)
                {
                    char symbol = expression[i];
                    if (isupper(symbol))
                    {
                        if (i + 1 < expression.size())
                        {
                            char nextSymbol = expression[i + 1];
                            if (!isupper(nextSymbol))
                            {
                                if (followSet[symbol].insert(nextSymbol).second)
                                    changed = true;
                            }
                            else
                            {
                                if (followSet.find(nextSymbol) != followSet.end())
                                {
                                    for (char s : followSet[nextSymbol])
                                    {
                                        if (followSet[symbol].insert(s).second)
                                            changed = true;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (followSet.find(variable) != followSet.end())
                            {
                                for (char s : followSet[variable])
                                {
                                    if (followSet[symbol].insert(s).second)
                                        changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return followSet;
}

int main()
{
    unordered_map<char, vector<string>> productions;
    char startSymbol;
    int numProductions;

    cout << "Enter the number of productions: ";
    cin >> numProductions;
    cout << "Enter grammar productions (e.g., S -> Ab):" << endl;
    for (int i = 0; i < numProductions; ++i)
    {
        char variable;
        string arrow, expression;
        cin >> variable >> arrow >> expression;
        productions[variable].push_back(expression);
    }

    cout << "Enter the start symbol: ";
    cin >> startSymbol;
    cout << "\n";

    auto firstSet = computeFirstSet(productions);

    auto followSet = computeFollowSet(productions, startSymbol);

    cout << "FIRST sets:\n";
    for (const auto &[variable, symbols] : firstSet)
    {
        cout << variable << ": ";
        for (char symbol : symbols)
        {
            cout << symbol << " ";
        }
        cout << endl;
    }

    cout << "\nFOLLOW sets:\n";
    for (const auto &[variable, symbols] : followSet)
    {
        cout << variable << ": ";
        for (char symbol : symbols)
        {
            cout << symbol << " ";
        }
        cout << endl;
    }

    return 0;
}
