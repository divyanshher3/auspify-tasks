Calculator Program
Objective
A command-line calculator that reads two numeric values and an arithmetic operator, then performs the selected calculation.
Technologies Used
- C++
- Standard input/output library: <iostream>
- A C++ compiler, such as g++ or Microsoft Visual C++ (MSVC)
No external libraries or frameworks are required.
Features Implemented
- Addition (+), subtraction (-), multiplication (*), and division (/)
- Checks whether the two number inputs are numeric
- Prevents division by zero
- Reports an invalid operator
Program Logic
The main() function:
1. Reads two values into float variables.
2. Checks cin.fail() and exits with status 1 if reading the numbers failed.
3. Reads a single operator character.
4. Uses a switch statement to perform the matching arithmetic operation and print the result.
5. Checks for a zero divisor before division.
The program handles one calculation per run.
Source Files
- calculatorProgram.cpp — C++ source code containing the calculator logic.
- calculatorProgram.exe — Windows executable included in the task folder.
How to Compile and Run
Open a terminal in the task1 folder.

With g++, compile the source:
g++ calculatorProgram.cpp -o calculatorProgram
On Windows, run:
.\calculatorProgram.exe
With MSVC, compile from a Developer Command Prompt:
cl /EHsc calculatorProgram.cpp
Then run:
calculatorProgram.exe
The program uses only the source file and the C++ standard library.
Sample Input and Output
Illustrative example for input values 12 and 4, with operator /:
Enter two numbers
12 4
enter the operation eg: + , - , / , *
/
asnwer : 3
This example illustrates the expected interaction based on the source code; it is not a claim that the program was executed.
Testing and Verification
Suggested cases to check:
- Addition, subtraction, multiplication, and division with ordinary numbers
- Entering non-numeric text for either number
- Dividing by zero
- Entering an unsupported operator such as %
- Using decimal and negative values
The source code was inspected. No separate test suite or test execution is included in this README.
Screenshots
Execution screenshots are stored in the task's screenshots/ folder.
Limitations and Improvements
- Input validation checks the two numbers, but does not separately check whether an operator was successfully read.
- The program handles only one operation per run.
- The displayed result label is spelled asnwer; it could be corrected to answer.
Conclusion
The program implements a basic interactive calculator using C++ input/output, variables, conditional validation, and a switch statement.