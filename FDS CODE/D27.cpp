#include<iostream>
#include<ctype.h>
#include<stack> // For stack operations
#include<string.h> // For string functions
using namespace std;

class Expression {
public:
    // Function for converting Infix to Postfix
    void conversion(char infix[20], char postfix[20]) {
        stack<char> s; // Stack for operators
        int j = 0; // Index for postfix
        char token, x;

        for (int i = 0; infix[i] != '\0'; i++) {
            token = infix[i];
            if (isalnum(token)) { // If token is an operand
                postfix[j] = token;
                j++;
            } else if (token == '(') {
                s.push(token); // Push '(' onto the stack
            } else if (token == ')') {
                // Pop from stack till '(' is found
                while (!s.empty() && (x = s.top()) != '(') {
                    postfix[j] = x;
                    j++;
                    s.pop();
                }
                s.pop(); // Pop '('
            } else {
                // Process operators
                while (!s.empty() && precedence(token) <= precedence(s.top())) {
                    x = s.top();
                    postfix[j] = x;
                    j++;
                    s.pop();
                }
                s.push(token); // Push current operator to stack
            }
        }

        // Pop all remaining operators from the stack
        while (!s.empty()) {
            postfix[j] = s.top();
            j++;
            s.pop();
        }
        postfix[j] = '\0'; // Null terminate the postfix expression
    }

    // Function to evaluate the Postfix expression
    int evaluatePostfix(char postfix[20]) {
        stack<int> s; // Stack for operands
        int result, x, y;
        
        for (int i = 0; postfix[i] != '\0'; i++) {
            char token = postfix[i];
            
            if (isalnum(token)) { // If token is operand, push its value onto the stack
                s.push(token - '0'); // Assuming single digit operand, convert char to integer
            } else { // If token is operator, pop operands and apply the operator
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                
                switch (token) {
                    case '+':
                        result = x + y;
                        break;
                    case '-':
                        result = x - y;
                        break;
                    case '*':
                        result = x * y;
                        break;
                    case '/':
                        result = x / y;
                        break;
                }
                s.push(result); // Push the result back to the stack
            }
        }
        
        // Final result will be the only element left in the stack
        return s.top();
    }

private:
    // Function to return precedence of operators
    int precedence(char x) {
        if (x == '(')
            return 0;
        if (x == '+' || x == '-')
            return 1;
        if (x == '*' || x == '/' || x == '%')
            return 2;
        else
            return 3;
    }
};

int main() {
    Expression exp;
    char infix[20], postfix[20];

    cout << "Enter the infix expression (single characters only): ";
    cin >> infix;

    // Conversion from infix to postfix
    exp.conversion(infix, postfix);
    cout << "Postfix expression is: " << postfix << endl;

    // Evaluating the postfix expression
    int result = exp.evaluatePostfix(postfix);
    cout << "Evaluation of the postfix expression: " << result << endl;

    return 0;
}