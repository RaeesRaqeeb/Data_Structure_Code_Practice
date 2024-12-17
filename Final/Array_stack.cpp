#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Stack {
public:
    char *arr;
    int size;
    int length;

    Stack(int size) {
        this->size = size;
        arr = new char[size];
        length = 0;
    }

    void push(char value) {
        if (length >= size) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[length] = value;
        length++;
    }

    char pop() {
        if (length <= 0) {
            cout << "Stack underflow" << endl;
            return '\0';
        }
        char temp = arr[length - 1];
        length--;
        return temp;
    }

 int expression_checker()
  {
    if (length == 0) {
        cout << "Stack is empty" << endl;
        return 0;
    }

    Stack obj(size);

    // Evaluate the expression from the stack (postfix notation)
    for (int i = 0; i < length; ++i)
     {
        char value = arr[i]; // Directly access the stack contents

        if (isdigit(value))
         {
            // Push operands onto the auxiliary stack
            obj.push(value);
        } else if (value == '+' || value == '-' || value == '*' || value == '/' || value == '%') {
            // Ensure there are enough operands for the operation
            if (obj.length < 2) {
                cout << "Insufficient operands for operator " << value << endl;
                return 0;
            }

            int num2 = obj.pop() - '0'; // Second operand
            int num1 = obj.pop() - '0'; // First operand
            int result;

            // Perform the operation
            if (value == '+') {
                result = num1 + num2;
            } else if (value == '-') {
                result = num1 - num2;
            } else if (value == '*') {
                result = num1 * num2;
            } else if (value == '/') {
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Division by zero error" << endl;
                    return 0;
                }
            } else if (value == '%') {
                result = num1 % num2;
            }

            // Push the result back onto the stack
            obj.push(result + '0'); // Convert result back to char
        } else {
            cout << "Invalid character in expression: " << value << endl;
            return 0;
        }
    }

    // The final result should be the only value left in the stack
    if (obj.length == 1) {
        return obj.pop() - '0'; // Convert final result back to int
    } else {
        cout << "Invalid expression" << endl;
        return 0;
    }
}


};

int main(void) {
    Stack obj(9);
    obj.push('5');
    obj.push('8');
    obj.push('1');
    obj.push('*');
    obj.push('2');
    obj.push('/');
    obj.push('+');
    obj.push('3');
    obj.push('-');

    cout << "Result: " << obj.expression_checker() << endl;

    return 0;
}