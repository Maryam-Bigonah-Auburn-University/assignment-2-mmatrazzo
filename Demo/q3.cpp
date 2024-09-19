#include <iostream>;
#include <iomanip>;

using namespace std;

// Declarations of functions to be used in the program
double convertToMPH(int minutes, int seconds);     // Convert minutes and seconds to MPH
double convertToMPH(double kph);     // Convert KPH to MPH

int main() {
    // Declare variables to be used in main()
    int minutes = 0;
    int seconds = 0;
    int selection = 0;
    double paceMPH = 0;
    double kph = 0.0;

    // Prompt user to select which type of conversion to run
    cout << "Enter 1 to convert minutes and seconds to MPH" << \
        " or Enter 2 to convert KPH to MPH" << endl;

    // Obtain user input for the selection
    cin >> selection;

    //"magic formula" to set the double output value's precision to two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Switch statement to obtain the required user input for conversion calculations
    switch(selection) {
    case 1:     // Minutes and Seconds to MPH
        // Prompt and obtain user input for pace in minutes and seconds
        cout << "Enter minutes:" << endl;
        cin >> minutes;

        cout << "Enter seconds:" << endl;
        cin >> seconds;

        // Call the function needed to convert minutes and seconds to MPH
        paceMPH = convertToMPH(minutes, seconds);

        // Print the result
        cout << "The pace is: " << paceMPH << " MPH" << endl;
        break;
    case 2:    // KPH to MPH
        // Prompt and obtain user input for pace in KPH
        cout << "Enter pace in kph:" << endl;
        cin >> kph;

        // Call the function needed to convert KPH to MPH
        paceMPH = convertToMPH(kph);

        // Print the result
        cout << "The pace is: " << paceMPH << " MPH" << endl;
        break;
    default:
        // Prompt and obtain user input for correct input if an invalid selection is entered
        cout << "Please enter a valid selection:" << endl;
        cin >> selection;
    }

    return 0;     // Terminate the program
}

// Function to convert a given pace in minutes and seconds to MPH
// The function returns the MPH result as a double
double convertToMPH(int minutes, int seconds) {
    // There are 3600 seconds in an hour
    return (3600.0 / ((minutes * 60) + seconds));
}

// Function to convert a given pace in KPH to MPH
// The function returns the MPH result as a double
double convertToMPH(double kph) {
    return (kph / 1.61);
}
