/*
 * Test Case - 1
 * Final Number = 2500
 * Operations = {"X + 10", "X - 5", "X * 5", "X ^ 2"}
 * Expected Output: 5
 * 
 * Test Case - 2
 * Final Number = 1000
 * Operations = {"X * 5", "X / 0", "X ^ 3"}
 * Expected Output: -1
 * 
 * Test Case - 3
 * Final Number: 10
 * Operations: {"X * 5", "X * 0", "X + 10"}
 * Expected Output : -2
 * 
 * Test Case - 4
 * Final Number: 617283948
 * Operations: {"X + 5”, “X - 0”, “X + 1”, “X / 2”, “X ^ 1”}
 * Expected Output: 1234567890
 */
#include<bits/stdc++.h>
using namespace std;

int guessNumber(int finalNumber, vector<string>& operations){
    double output = finalNumber;

    while (operations.size() > 0)
    {
        double operand2 = stoi(operations[operations.size() - 1].substr(4, operations[operations.size() - 1].length()));
        ;
        char operation = operations[operations.size() - 1][2];
        switch (operation)
        {
        case '+':
            output -= operand2;
            break;
        case '-':
            output += operand2;
            break;
        case '*':
            if (operand2 == 0)
            {
                return -2;
            }
            output /= operand2;
            break;
        case '/':
            if (operand2 == 0)
            {
                return -1;
            }
            output *= operand2;
            break;
        case '^':
            if (operand2 == 0)
            {
                return -2;
            }
            output = pow(output, 1.0 / operand2);
            break;
        case '%':
            return -2; // since undoing modulo on a number results in more than one answer
        default:
            return -1; // invalid operation
        }
        operations.pop_back();
    }
    return output;
}

int main(){
    int finalNumber = 2500;
    vector<string> operations = {"X + 10", "X - 5", "X * 5", "X ^ 2"};

    int actualNumber = guessNumber(finalNumber, operations);
    cout << actualNumber << endl;
    return 0;
}
