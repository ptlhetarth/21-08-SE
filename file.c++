// program to demonstrate the ATM banking system
#include <iostream> // For input/output operations (cin, cout)
#include <string> // For string manipulation
#include <iomanip> // For setting precision (std::fixed, std::setprecision)
#include <limits> // For numeric_limits to clear input buffer
#include <thread> // For std::this_thread::sleep_for (requires C++11 or later)
#include <chrono> // For std::chrono::seconds (requires C++11 or later)
#include <ctime> // For time functions (time_t, localtime, strftime)

// --- Global Variables (for simplicity in this example) ---
const std::string CORRECT_PIN = "12345";
double currentBalance = 20000.00; // Starting balance as Rs. 20000

// --- Utility Functions ---

// Function to print a separator line
void printSeparator() {
    std::cout << "\n" << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << "\n";
}

// Function to print a header line with a title
void printHeader(const std::string& title) {
    printSeparator();
    int padding = (80 - title.length()) / 2;
    std::cout << std::setw(padding) << "" << title << std::endl;
    printSeparator();
}

// Function to pause execution until a key is pressed
void pressAnyKeyToContinue() {
    std::cout << "\nPress any key to continue... ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer before getting input
    std::cin.get(); // Wait for a key press
}

// --- ATM Screen Functions ---

// Displays the initial welcome screen
void displayWelcomeScreen() {
    // Get current date and time
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char dateTimeStr[80];
    strftime(dateTimeStr, sizeof(dateTimeStr), "%a %b %d %H:%M:%S %Y", ltm);

    printHeader("WELCOME TO ATM");
    std::cout << "\n";
    std::cout << "--------------------------------\n";
    std::cout << "Current date : " << dateTimeStr << "\n";
    std::cout << "--------------------------------\n";
    std::cout << "\nPress 1 and Then Press Enter to Access Your Account Via Pin Number\n";
    std::cout << " or\n";
    std::cout << "Press 0 and press Enter to get Help.\n";
    printSeparator();
}

// Displays the help screen (Choice 2 in the image, but triggered by 0)
void displayHelpScreen() {
    printHeader("ATM ACCOUNT STATUS");
    std::cout << "\nYou must have the correct pin number to access this account. ";
    std::cout << "See your\nbank representative for assistance during bank opening hours\n";
    std::cout << "\nThanks for, your choice today!!\n";
    printSeparator();
    pressAnyKeyToContinue();
}

// Displays the ATM Account Access screen for PIN entry
bool displayPinEntryScreen() {
    printHeader("ATM ACCOUNT ACCESS");
    std::string enteredPin;
    std::cout << "\nEnter Your Acc Pin Access Number! [Only one attempt is allowed]\n";
    std::cout << "> ";
    std::cin >> enteredPin;

    if (enteredPin == CORRECT_PIN) {
        return true;
    } else {
        printHeader("THANK YOU");
        std::cout << "\nYou had made your attempt which failed!!! No More attempts allowed!! Sorry!!\n";
        printSeparator();
        pressAnyKeyToContinue();
        return false;
    }
}

// Displays the main ATM menu after successful PIN entry
void displayMainMenu() {
    printHeader("ATM Main Menu Screen");
    std::cout << "\nEnter [1] To Deposit Cash\n";
    std::cout << "Enter [2] To Withdraw Cash\n";
    std::cout << "Enter [3] To Balance Inquiry\n";
    std::cout << "Enter [0] To Exit ATM\n";
    std::cout << "\nPLEASE ENTER A SELECTION AND PRESS RETURN KEY:\n";
    printSeparator();
}

// Handles the deposit operation
void depositCash() {
    printHeader("ATM ACCOUNT DEPOSIT SYSTEM");
    std::cout << "\nThe Names of the Account Holders are : Rakesh Kharva\n";
    std::cout << "The Account Holders' address is :Mumbai\n";
    std::cout << "The Branch location is :Andheri\n";
    std::cout << "Account number :5678\n";
    std::cout << std::fixed << std::setprecision(2); // Set output to 2 decimal places

    std::cout << "\nPresent available balance :Rs. " << currentBalance << "\n";
    std::cout << "Enter the Amount to be Deposited Rs. ";
    double depositAmount;
    std::cin >> depositAmount;

    if (depositAmount > 0) {
        currentBalance += depositAmount;
        std::cout << "Your new available Balanced Amount is Rs. " << currentBalance << "\n";
        std::cout << "\nThank You!\n";
    } else {
        std::cout << "\nInvalid deposit amount. Please enter a positive value.\n";
    }
    printSeparator();
    pressAnyKeyToContinue();
}

// Handles the withdrawal operation
void withdrawCash() {
    printHeader("ATM ACCOUNT WITHDRAW SYSTEM");
    std::cout << std::fixed << std::setprecision(2); // Set output to 2 decimal places

    std::cout << "\nPresent available balance :Rs. " << currentBalance << "\n";
    std::cout << "Enter the Amount to be Withdrawn Rs. ";
    double withdrawAmount;
    std::cin >> withdrawAmount;

    if (withdrawAmount > 0 && withdrawAmount <= currentBalance) {
        currentBalance -= withdrawAmount;
        std::cout << "Your new available Balanced Amount is Rs. " << currentBalance << "\n";
        std::cout << "\nTransaction Successful!\n";
    } else if (withdrawAmount <= 0) {
        std::cout << "\nInvalid withdrawal amount. Please enter a positive value.\n";
    } else {
        std::cout << "\nInsufficient balance. Your current balance is Rs. " << currentBalance << "\n";
        std::cout << "Please try a lower amount.\n";
    }
    printSeparator();
    pressAnyKeyToContinue();
}

// Handles the balance inquiry operation
void balanceInquiry() {
    printHeader("ATM BALANCE INQUIRY");
    std::cout << "\nThe Names of the Account Holders are : Rakesh Kharva\n";
    std::cout << "The Account Holders' address is :Mumbai\n";
    std::cout << "The Branch location is :Andheri\n";
    std::cout << "Account number :5678\n";

    std::cout << std::fixed << std::setprecision(2); // Set output to 2 decimal places
    std::cout << "\nYour Current Account Balance is :Rs. " << currentBalance << "\n";
    std::cout << "\nThank You!\n";
    printSeparator();
    pressAnyKeyToContinue();
}

// --- Main Program ---
int main() {
    int welcomeChoice;
    bool loggedIn = false;

    // --- Initial Welcome Screen and Access Choice ---
    displayWelcomeScreen();
    std::cout << "Enter your choice: ";
    std::cin >> welcomeChoice;

    if (welcomeChoice == 1) {
        loggedIn = displayPinEntryScreen();
    } else if (welcomeChoice == 0) {
        displayHelpScreen();
        // After help, the program exits or restarts the welcome screen.
        // For this example, we'll exit, as shown in the flow.
        return 0;
    } else {
        printSeparator();
        std::cout << "Invalid choice. Exiting.\n";
        printSeparator();
        // Short pause before exiting
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 0;
    }

    // --- ATM Main Menu Loop (if logged in) ---
    if (loggedIn) {
        int menuChoice;
        do {
            displayMainMenu();
            std::cout << "Enter your selection: ";
            std::cin >> menuChoice;

            // Clear input buffer after numeric input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (menuChoice) {
                case 1:
                    depositCash();
                    break;
                case 2:
                    withdrawCash();
                    break;
                case 3:
                    balanceInquiry();
                    break;
                case 0:
                    printHeader("THANK YOU FOR USING ATM");
                    std::cout << "\nHave a great day!\n";
                    printSeparator();
                    break;
                default:
                    printSeparator();
                    std::cout << "Invalid option. Please try again.\n";
                    printSeparator();
                    pressAnyKeyToContinue();
                    break;
            }
        } while (menuChoice!= 0);
    }

    return 0;
}