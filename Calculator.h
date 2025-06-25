#include <iostream>
#include "Stack.h"
using namespace std;

class Calculator
{
    private:
        string Exp;
        string PostFix; // Fix: should be PostFix, not Token
        float Result;
        Stack<char> OperatorStack;

        int Precedence(char one, char two)
        {
            // Returns 1 if precedence(one) > precedence(two), 0 if equal, -1 if less
            if ((one == '+' && two == '+') || (one == '-' && two == '+') ||
                (one == '+' && two == '-') || (one == '-' && two == '-'))
                return 0;
            else if ((one == '*' && (two == '+' || two == '-')) ||
                     (one == '/' && (two == '+' || two == '-')))
                return 1; // one has higher precedence
            else if ((one == '+' || one == '-') && (two == '*' || two == '/'))
                return -1; // two has higher precedence
            else if (one == '(' && two != ')')
                return 1; // one is opening bracket
            else if (one != '(' && two == ')')
                return -1; // two is closing bracket
            else if (one == '(' && two == ')')
                return 0; // both are brackets
            else
                return 0; // default case for other operators
        }

        void Tokenizer()
        {
            PostFix = ""; // Clear PostFix before use
            for (size_t idx = 0; idx < Exp.length(); ++idx)
            {
                char ch = Exp[idx];
                if (isalnum(ch))
                {
                    PostFix += ch;
                }
                else if (ch == '(')
                {
                    OperatorStack.push(ch);
                }
                else if (ch == ')')
                {
                    while (!OperatorStack.isEmpty() && OperatorStack.peek() != '(')
                    {
                        PostFix += OperatorStack.pop();
                    }
                    if (!OperatorStack.isEmpty() && OperatorStack.peek() == '(')
                        OperatorStack.pop(); // Remove '(' from stack
                }
                else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
                {
                    while (!OperatorStack.isEmpty() && OperatorStack.peek() != '(' &&
                           Precedence(OperatorStack.peek(), ch) >= 0)
                    {
                        PostFix += OperatorStack.pop();
                    }
                    OperatorStack.push(ch);
                }
            }
            while (!OperatorStack.isEmpty())
            {
                char op = OperatorStack.pop();
                if (op != '(' && op != ')')
                    PostFix += op;
            }
        }

    public:
        Calculator(string& exp);
        void displayToken()
        {
            cout << "PostFix: " << PostFix << endl;
        }
        void Calculate();

        void displayTokenizer()
        {
            cout << "PostFix: in Postfix form: " << PostFix << endl;
        }
        void displayResult()
        {
            cout << "Result : " << Result << endl;
        }
};

Calculator::Calculator(string &exp) : Exp(exp) { PostFix = ""; }

void Calculator::Calculate()
{
    Tokenizer();
    Stack<float> OperandStack;

    for (size_t idx = 0; idx < PostFix.length(); ++idx) // Fix: use PostFix, not Token
    {
        char ch = PostFix[idx];
        if (isdigit(ch))
        {
            OperandStack.push(ch - '0'); // Convert char to int
        }
        else
        {
            float right = OperandStack.pop();
            float left = OperandStack.pop();
            switch (ch)
            {
                case '+': OperandStack.push(left + right); break;
                case '-': OperandStack.push(left - right); break;
                case '*': OperandStack.push(left * right); break;
                case '/': OperandStack.push(left / right); break;
            }
        }
    }
    Result = OperandStack.pop();
}

