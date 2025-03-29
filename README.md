# Infix Expression Evaluator

## Overview 
This project is a C-based application designed to evaluate mathematical expressions written in **infix notation**. The program uses **stacks** to:
- Convert infix expressions to **postfix notation** (Reverse Polish Notation).
- Evaluate the postfix expression based on **operator precedence** and **associativity**.
- Support basic arithmetic operations (+, -, *, /), as well as **exponentiation** (`^`).

## Features
- Converts infix expressions to postfix.
- Handles **operator precedence**: 
  - `*`, `/` have higher precedence than `+`, `-`.
  - `^` (exponentiation) has the highest precedence.
- Supports parentheses for grouping expressions.
- Handles **invalid expressions** such as unbalanced parentheses, division by zero, and invalid operator placement.
- **Exponentiation** is supported (e.g., `2^3`).

## Requirements
- **C Compiler** (GCC, MinGW, etc.)
- **Operating System**: Any system with C development tools.

## Usage
1. **Clone or download** this repository.
2. **Compile** the C program using a C compiler.
    - Example with GCC:  
      ```
      gcc -o infix_evaluator infix_evaluator.c
      ```
3. **Run the program**:
    ```
    ./infix_evaluator
    ```
4. Enter a mathematical expression in infix format when prompted.

Example expressions:
- `3 + 5 * 2`
- `(3 + 5) * 2 - 4 / 2`
- `2 ^ 3 + 4`

## Example

### Input:
Enter the expression: (3 + 5) * 2 - 4 / 2


### Output:

Result: 14


## Approach & Explanation

The program uses **two stacks**:
1. **Operator Stack**: Stores operators (`+`, `-`, `*`, `/`, `^`) and parentheses `(`, `)`.
2. **Number Stack**: Stores operands (numbers).

### Steps:
1. **Parsing the Expression**: 
   - The program iterates through the expression character by character.
   - If a number is encountered, it is pushed onto the **Number Stack**.
   - If an operator is encountered, it is pushed onto the **Operator Stack**, but only after checking the **operator precedence** to decide whether operators already on the stack should be applied first.
   - Parentheses are handled by pushing `(` onto the stack and popping operators until `)` is encountered.
   
2. **Operator Precedence**: 
   - The program ensures that multiplication and division have higher precedence than addition and subtraction.
   - Exponentiation (`^`) is given the highest precedence.
   
3. **Evaluating the Expression**: 
   - Once the expression is fully parsed, the program processes remaining operators in the stack and applies them to the numbers in the **Number Stack**.

### Example of Postfix Conversion:
**Infix**: `(3 + 5) * 2 - 4 / 2`  
**Postfix**: `3 5 + 2 * 4 2 / -`

## Error Handling
- **Unbalanced Parentheses**: The program detects mismatched parentheses and outputs an error.
- **Division by Zero**: If division by zero is encountered, an error message is displayed.
- **Invalid Expression**: If an operator appears in an invalid position (e.g., `5 + * 3`), the program will catch the error and notify the user.

## Example Test Cases

### Test Case 1:
**Input**:

(3 + 5) * 2 - 4 / 2

**Output**:

Result: 14


### Test Case 2:
**Input**:

3 + 5 * 2

**Output**:

Result: 13


### Test Case 3:
**Input**:

2 ^ 3 + 4

**Output**:

Result: 12


### Test Case 4 (Divide by Zero):
**Input**:

10 / 0

**Output**:

Error: Invalid or unbalanced expression!


### Test Case 5 (Invalid Expression):
**Input**:

5 + * 3

**Output**:

Error: Invalid or unbalanced expression!


## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
