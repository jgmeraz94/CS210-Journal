#include <iostream>
#include <string>
#include "Clock.h"
const char* options[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
using namespace std;

// Returns a string with n repetitions of character c
string nCharString(size_t n, char c) {
    return string(n, c);
}

// Prints a formatted menu given options and menu width
void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {
    cout << nCharString(width, '*') << endl;
    for (unsigned int i = 0; i < numStrings; ++i) {
        string menuItem = strings[i];
        string itemLine = "* " + to_string(i + 1) + " - " + menuItem;
        int spacesNeeded = width - 1 - itemLine.length();
        itemLine += nCharString(spacesNeeded > 0 ? spacesNeeded : 0, ' ') + "*";
        cout << itemLine << endl;
        if (i != numStrings - 1) cout << endl;
    }
    cout << nCharString(width, '*') << endl;
}

// Prompts user to select a valid menu option
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    while (true) {
        cin >> choice;
        if (choice >= 1 && choice <= maxChoice) break;
    }
    return choice;
}

// Displays the clock in both 12-hour and 24-hour formats side by side
void displayClocks(const Clock& clock) {
    string t12 = clock.formatTime12();
    string t24 = clock.formatTime24();

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << "*      12-HOUR CLOCK      *" << nCharString(3, ' ') << "*      24-HOUR CLOCK      *" << endl;
    cout << endl;

    size_t padLeft12 = (25 - t12.size()) / 2;
    size_t padRight12 = 25 - t12.size() - padLeft12;

    size_t padLeft24 = (25 - t24.size()) / 2;
    size_t padRight24 = 25 - t24.size() - padLeft24;

    cout << "*" << nCharString(padLeft12, ' ') << t12 << nCharString(padRight12, ' ') << "*" << nCharString(3, ' ')
        << "*" << nCharString(padLeft24, ' ') << t24 << nCharString(padRight24, ' ') << "*" << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

// Main menu loop to allow user interaction with clock
void mainMenu() {
    Clock clock;
    char* options[] = { (char*)"Add One Hour", (char*)"Add One Minute", (char*)"Add One Second", (char*)"Exit Program" };
    unsigned int choice;
    do {
        displayClocks(clock);
        printMenu(options, 4, 26);
        choice = getMenuChoice(4);
        if (choice == 1) clock.addOneHour();
        else if (choice == 2) clock.addOneMinute();
        else if (choice == 3) clock.addOneSecond();
    } while (choice != 4);
}

int main() {
    mainMenu();
    return 0;
}
