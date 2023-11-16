#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

// Token types
enum TokenType {
    NUMBER,
    OPERATOR,
    EQUAL,
    UNKNOWN
};

// Token structure
struct Token {
    TokenType type;
    string value;
};

// Function to determine if a string is an operator
bool isOperator(const string& s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

// Function to tokenize a string
vector<Token> tokenize(const string& expression) {
    istringstream stream(expression);
    vector<Token> tokens;
    string token;

    while (stream >> token) {
        Token t;

        // Determine token type
        if (isdigit(token[0])) {
            t.type = NUMBER;
        } else if (isOperator(token)) {
            t.type = OPERATOR;
        } else if (token == "=") {
            t.type = EQUAL;
        } else {
            t.type = UNKNOWN;
        }

        t.value = token;
        tokens.push_back(t);
    }

    return tokens;
}

int main() {
    ifstream inputFile("expression.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Read expression from file
    string expression;
    getline(inputFile, expression);

    // Tokenize the expression
    vector<Token> tokens = tokenize(expression);

    // Output description of tokens and operators
    cout << "Tokens and Operators:" << endl;
    for (const auto& token : tokens) {
        cout << "Type: ";
        switch (token.type) {
            case NUMBER:
                cout << "Number";
                break;
            case OPERATOR:
                cout << "Operator";
                break;
            case EQUAL:
                cout << "Equal";
                break;
            case UNKNOWN:
                cout << "Unknown";
                break;
        }
        cout << ", Value: " << token.value << endl;
    }

    // Close the file
    inputFile.close();

    return 0;
}
