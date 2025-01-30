#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>

using namespace std;

class Calculator {
public:
    // Function for addition
    double add(double a, double b) {
        return a + b;
    }

    // Function for subtraction
    double subtract(double a, double b) {
        return a - b;
    }

    // Function for multiplication
    double multiply(double a, double b) {
        return a * b;
    }

    // Function for division
    double divide(double a, double b) {
        if (b == 0) {
            throw invalid_argument("Error: Division by zero is not allowed.");
        }
        return a / b;
    }

    // Function for square root
    double squareRoot(double a) {
        if (a < 0) {
            throw invalid_argument("Error: Cannot take square root of a negative number.");
        }
        return sqrt(a);
    }

    // Function for power
    double power(double a, double b) {
        return pow(a, b);
    }

    // Function for modulus
    double modulus(double a, double b) {
        if (b == 0) {
            throw invalid_argument("Error: Division by zero is not allowed.");
        }
        return fmod(a, b);
    }

    // Function to display the menu
    void displayMenu() {
        cout << "\nSimple Calculator\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Square Root\n";
        cout << "6. Power\n";
        cout << "7. Modulus\n";
        cout << "8. Exit\n";
    }
};

// Function to get user input
double getInput() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return value;
        }
    }
}

int main() {
    Calculator calc;
    int choice;
    double num1, num2;
    
    do {
        calc.displayMenu();
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1: // Add
                cout << "Enter two numbers: ";
                num1 = getInput();
                num2 = getInput();
                cout << "Result: " << calc.add(num1, num2) << endl;
                break;

            case 2: // Subtract
                cout << "Enter two numbers: ";
                num1 = getInput();
                num2 = getInput();
                cout << "Result: " << calc.subtract(num1, num2) << endl;
                break;

            case 3: // Multiply
                cout << "Enter two numbers: ";
                num1 = getInput();
                num2 = getInput();
                cout << "Result: " << calc.multiply(num1, num2) << endl;
                break;

            case 4: // Divide
                cout << "Enter two numbers: ";
                num1 = getInput();
                num2 = getInput();
                try {
                    cout << "Result: " << calc.divide(num1, num2) << endl;
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;

            case 5: // Square Root
                cout << "Enter a number: ";
                num1 = getInput();
                try {
                    cout << "Result: " << calc.squareRoot(num1) << endl;
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;

            case 6: // Power
                cout << "Enter base and exponent: ";
                num1 = getInput();
                num2 = getInput();
                cout << "Result: " << calc.power(num1, num2) << endl;
                break;

            case 7: // Modulus
                cout << "Enter two numbers: ";
                num1 = getInput();
                num2 = getInput();
                try {
                    cout << "Result: " << calc.modulus(num1, num2) << endl;
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;

            case 8: // Exit
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please choose a valid option." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
