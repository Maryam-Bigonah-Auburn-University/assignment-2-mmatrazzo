#include<iostream>
#include<String>

using namespace std;

// Declarations of functions to be used in the program
bool isleapYear(int year);    // Check if a year is a leap year
int getCenturyValue (int year);     // Obtain the century value for a given year
int getYearValue(int year);     // Obtain the year value for a given year
int getMonthValue(int month, int year);     // Obtain the month value for a given month and year

int main() {
    // Declare variables to be used in main()
    int month;
    int day = 0;
    int year = 0;
    int sum = 0;
    int day_of_week = 0;
    string day_string = "";

    // Prompt user to input the month
    cout << "Please enter the month:" << endl;

    // Obtain user input for the month
    cin >> month;

    // Ensure a valid month has been entered. Prompt user for valid month if needed.
    while (month < 1 || month > 12){
        cout << "Invalid entry. Please enter a valid month:" << endl;
        cin >> month;
    }

    // Prompt user to input the day
    cout << "Please enter a day:" << endl;

    // Obtain user input for the day
    cin >> day;

    // Ensure a valid day has been entered. Prompt user for valid day if needed.
    while (day < 1 || day > 31){
        cout << "Invalid entry. Please enter a valid day:" << endl;
        cin >> day;     // Obtain user input for the day
    }

    // Ensure a valid day has been entered for months with 30 days. Prompt user for valid day if needed.
    if (month == 4 || month == 6|| month == 9 || month == 11 ){

        while (day < 1 || day > 30) {
            cout << "Invalid entry. Please enter a value between 1 and 30:" << endl;
            cin  >> day;     // Obtain user input for the day
        }
    }

    // Ensure a valid day has been entered for month with 28 or 29 days. Prompt user for valid day if needed.
    if (month == 2) {
        while (day < 1 || day > 29){
            cout << "Invalid entry. Please enter a value between 1 and 29:" << endl;
            cin >> day;     // Obtain user input for the day
        }
    }

    // Prompt user to input the year
    cout << "Enter a year (4 digits):" << endl;

    // Obtain user input for the year
    cin >> year;

    // Calculate the day of week
    sum = day + getMonthValue(month,year) + getYearValue(year) + getCenturyValue(year);
    day_of_week = sum % 7;

    // Switch statement to find the corresponding day name
    switch(day_of_week) {
    case 0:
        day_string = "Sunday";
        break;
    case 1:
        day_string = "Monday";
        break;
    case 2:
        day_string = "Tuesday";
        break;
    case 3:
        day_string = "Wednesday";
        break;
    case 4:
        day_string = "Thursday";
        break;
    case 5:
        day_string = "Friday";
        break;
    case 6:
        day_string = "Saturday";
        break;
}

    // Print result for user
    cout << "The day of the week for " << month << "/" << day << "/" << year << " is " << day_string << endl;

    return 0;     // Terminate the program

}

// Function to determine if a given year is a leap year
bool isLeapYear(int year) {
    // Leap year is divisible by 400 or divisible by 4 and not 100
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

// Function to determine the century value for a given year
// Function returns the appropriate century value
int getCenturyValue(int year) {
    int century = 0;     //use int since a decimal will always be rounded down
    int century_value = 0;

    century = year / 100;
    century_value = (3 - (century % 4)) * 2;
    return century_value;
}

// Function to determine the year value for a given year
// Function returns the appropriate year value
int getYearValue(int year) {
    int year_digits = 0;
    int year_value = 0;

    year_digits = year % 100;
    year_value = (year_digits / 4);
    return year_digits + year_value;
}

// Function to determine the month value for a given month and year
// Function returns the appropriate month value
int getMonthValue(int month, int year) {
    switch(month) {
    case 1:     // January
        if (isLeapYear(year) == true)     // Perform if the year is a leap year
            return 6;
        else
            return 0;
    case 2:     // February
        if (isLeapYear(year) == true)     // Perform if the year is a leap year
            return 2;
        else
            return 3;
    case 3:     // March
        return 3;
    case 4:     // April
        return 6;
    case 5:     // May
        return 1;
    case 6:     // June
        return 4;
    case 7:     // July
        return 6;
    case 8:     // August
        return 2;
    case 9:     // September
        return 5;
    case 10:     // October
        return 0;
    case 11:     // November
        return 3;
    case 12:     // December
        return 5;
    }
}
