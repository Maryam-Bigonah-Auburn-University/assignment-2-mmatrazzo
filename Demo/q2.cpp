#include <iostream>;

using namespace std;

// Declarations of functions to be used in the program
void computeCoin(int coinValue, int& number, int& amountLeft);     // Compute coins needed
void printOutput(int coinValue, int number);     // Print result

int main() {
    // Declare variables to be used in main()
    char compute_again = 'N';
    int number = 0;
    int amountLeft = 0;

    // Perform the following loop until compute_again is set to something other than "Y" by user input
    do {
        // Prompt and obtain user input for the amount of change on-hand
        cout << "Enter the amount of change:" << endl;
        cin  >> amountLeft;

        // Ensure the amount of change is between 1 and 99. Prompt and obtain user input for valid input as needed.
        while (amountLeft < 1 || amountLeft > 99) {
            cout << "Invalid input. Please enter a value between 1 and 99:" << endl;
            cin  >> amountLeft;
        }

        // Call the functions needed to determine the required number of each coin denomination
        cout << "Change can be given as:" << endl;
        computeCoin(25,number,amountLeft);     // Quarters
        printOutput(25,number);
        computeCoin(10,number,amountLeft);     // Dimes
        printOutput(10,number);
        computeCoin(1,number,amountLeft);     // Pennies
        printOutput(1,number);

        // Prompt and obtain user input to determine if the loop should be run again
        cout << "Do you want to make change again?" << endl
             << "Enter Y to convert again and any other key to exit:" << endl;
        cin  >> compute_again;

    } while(compute_again == 'Y' || compute_again == 'y');


    return 0;     // Terminate the program
}

// Function to compute the number of coins of a particular denomination that are needed
// The function does not return anything since call-by-reference is employed
void computeCoin(int coinValue, int& number, int& amountLeft) {
    number = amountLeft / coinValue;
    amountLeft = amountLeft - (number * coinValue);
}

// Function to display the result of the program to the user
// The function does not return anything
void printOutput(int coinValue, int number) {
    cout << number;

    // Switch statement to print the appropriate coin denomination
    switch(coinValue) {
    case 25:
        cout << " quarters" << endl;
        break;
    case 10:
        cout << " dimes" << endl;
        break;
    case 1:
         cout << " pennies" << endl;
    }
}
