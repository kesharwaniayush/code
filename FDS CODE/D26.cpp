#include <iostream>
#include <cstring> // For strlen function
using namespace std;

int top;
char str[20];

// Push character onto stack
void push(char a) {
    top++;
    str[top] = a;
}

// Pop character from stack
void pop() {
    top--;
}

// Function to check if the expression is well-parenthesized
void input() {
    char ch[20];
    int i = 0;
    top = -1; // Initialize stack

    cout << "\nEnter the Expression: ";
    cin >> ch;  // Take input expression

    while (ch[i] != '\0') {
        if ((ch[i] == '{') || (ch[i] == '[') || (ch[i] == '(')) {
            // Push opening brackets onto the stack
            push(ch[i]);
        }
        else if (ch[i] == '}') {
            // Check for corresponding opening bracket for '}'
            if (top == -1 || str[top] != '{') {
                cout << "\n'Missing opening {' for '}'" << endl;
                return;
            } else {
                pop(); // Pop the matching '{'
            }
        }
        else if (ch[i] == ']') {
            // Check for corresponding opening bracket for ']'
            if (top == -1 || str[top] != '[') {
                cout << "\n'Missing opening [' for ']'" << endl;
                return;
            } else {
                pop(); // Pop the matching '['
            }
        }
        else if (ch[i] == ')') {
            // Check for corresponding opening bracket for ')'
            if (top == -1 || str[top] != '(') {
                cout << "\n'Missing opening (' for ')'" << endl;
                return;
            } else {
                pop(); // Pop the matching '('
            }
        }
        i++;
    }

    // If stack is empty after processing the entire expression, it's well-parenthesized
    if (top == -1) {
        cout << "\nExpression is well-parenthesized." << endl;
    } else {
        // If stack is not empty, there are unmatched opening brackets
        while (top != -1) {
            if (str[top] == '{') {
                cout << "\n'Missing closing }' for {" << endl;
            } else if (str[top] == '[') {
                cout << "\n'Missing closing ]' for ['" << endl;
            } else if (str[top] == '(') {
                cout << "\n'Missing closing )' for ('" << endl;
            }
            pop();
        }
        cout << "\nExpression is not well-parenthesized." << endl;
    }
}

int main() {
    input();
    return 0;
}