#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Stack for operators
char operatorStack[20];
// Stack for numbers
int numStack[20];
int topOperator = -1;
int topNum = -1;

// Function to push operators onto the operator stack
void pushOperator(char x) {
    operatorStack[++topOperator] = x;
}

// Function to pop operators from the operator stack
char popOperator() {
    if (topOperator == -1) {
        return -1;
    }
    return operatorStack[topOperator--];
}

// Function to push numbers onto the number stack
void pushNum(int x) {
    numStack[++topNum] = x;
}

// Function to pop numbers from the number stack
int popNum() {
    if (topNum == -1) {
        return -1;
    }
    return numStack[topNum--];
}

// Function to get precedence of operators
int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1;
}

// Function to check if the string is a valid expression
int isValidExpression(char *expression) {
    int open = 0;
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(') open++;
        else if (expression[i] == ')') open--;
        if (open < 0) return 0;  // Unbalanced parentheses
    }
    return open == 0;  // True if balanced
}

// Function to perform arithmetic operations
int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;  // Handle divide by zero
        case '^': {
            int result = 1;
            for (int i = 0; i < operand2; i++) {
                result *= operand1;
            }
            return result;
        }
        default: return 0;
    }
}

// Function to evaluate the expression
int evaluate(char *expression) {
    char *e = expression;
    char x;
    int operand1, operand2;

    while (*e != '\0') {
        if (isdigit(*e)) {  // If the character is a number
            int num = *e - '0';  // Convert character to number
            pushNum(num);
        } else if (*e == '(') {
            pushOperator(*e);  // Push '(' to the operator stack
        } else if (*e == ')') {
            while ((x = popOperator()) != '(') {  // Process till '('
                operand2 = popNum();
                operand1 = popNum();
                int result = performOperation(operand1, operand2, x);
                pushNum(result);
            }
        } else if (*e == '+' || *e == '-' || *e == '*' || *e == '/' || *e == '^') {
            while (topOperator != -1 && priority(operatorStack[topOperator]) >= priority(*e)) {
                x = popOperator();
                operand2 = popNum();
                operand1 = popNum();
                int result = performOperation(operand1, operand2, x);
                pushNum(result);
            }
            pushOperator(*e);
        }
        e++;
    }

    while (topOperator != -1) {  // Process the remaining operators
        x = popOperator();
        operand2 = popNum();
        operand1 = popNum();
        int result = performOperation(operand1, operand2, x);
        pushNum(result);
    }

    return popNum();  // Return the final result
}

int main() {
    char expression[20];

    printf("Enter the expression: ");
    scanf("%s", expression);

    if (!isValidExpression(expression)) {
        printf("Error: Invalid or unbalanced expression!\n");
        return -1;
    }

    int result = evaluate(expression);
    printf("Result: %d\n", result);

    return 0;
}
