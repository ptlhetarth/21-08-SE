#include <iostream>

// Function to print a separator line
void printSeparator() {
    std::cout << "==================================================" << std::endl;
}

// Function to display the main ATM menu
void displayMainMenu() {
    printSeparator();
    std::cout << " ATM Main Menu Screen " << std::endl;
    printSeparator();
    std::cout << "Enter [1] To Deposit Cash" << std::endl;
    std::cout << "Enter [2] To Withdraw Cash" << std::endl;
    std::cout << "Enter [3] To Balance Inquiry" << std::endl;
    std::cout << "Enter [0] To Exit ATM" << std::endl;
    std::cout << "PLEASE ENTER A SELECTION AND PRESS RETURN KEY:" << std::endl;
    printSeparator();
}

// Function to display account details
void displayAccountDetails() {
    std::cout << "The Names of the Account Holders are :Rakesh Kharva" << std::endl;
    std::cout << "The Account Holders' address is :Mumbai" << std::endl;
    std::cout << "The Branch location is :Andheri" << std::endl;
    std::cout << "Account number :5678" << std::endl;
    printSeparator();
}

int main() {
    int choice;
    int pin;
    int correctPin = 12345; // Fixed PIN for demonstration
    double balance = 20000.0; // Initial balance
    double depositAmount;
    double withdrawAmount;

    // Welcome Screen
    printSeparator();
    std::cout << " WELCOME TO ATM " << std::endl;
    printSeparator();
    std::cout << "Current date : Mon Aug 22 15:00:59 2022" << std::endl;
    printSeparator();
    std::cout << "Press 1 and Then Press Enter to Access Your Account Via Pin Number" << std::endl;
    std::cout << "or" << std::endl;
    std::cout << "Press 0 and press Enter to get Help." << std::endl;
    printSeparator();

    std::cin >> choice;

    if (choice == 1) {
        // ATM Account Access
        printSeparator();
        std::cout << " ATM ACCOUNT ACCESS " << std::endl;
        printSeparator();
        std::cout << "Enter Your Acc Pin Access Number! [Only one attempt is allowed]" << std::endl;
        printSeparator();
        std::cin >> pin;

        if (pin == correctPin) {
            // Correct PIN, show main menu
            int menuChoice;
            do {
                displayMainMenu();
                std::cin >> menuChoice;

                switch (menuChoice) {
                    case 1: // Deposit Cash
                        printSeparator();
                        std::cout << " ATM ACCOUNT DEPOSIT SYSTEM " << std::endl;
                        printSeparator();
                        displayAccountDetails();
                        std::cout << "Present available balance :Rs. " << balance << std::endl;
                        std::cout << "Enter the Amount to be Deposited Rs. ";
                        std::cin >> depositAmount;
                        balance += depositAmount;
                        std::cout << "Your new available Balanced Amount is Rs. " << balance << std::endl;
                        std::cout << "Thank You!" << std::endl;
                        std::cout << "Press any key to Return to the Main Menu" << std::endl;
                        std::cin.ignore(); // Consume newline
                        std::cin.get(); // Wait for a key press
                        break;
                    case 2: // Withdraw Cash
                        printSeparator();
                        std::cout << " ATM ACCOUNT WITHDRAWAL " << std::endl;
                        printSeparator();
                        displayAccountDetails();
                        std::cout << "Present available balance :Rs. " << balance << std::endl;
                        std::cout << "Enter the Amount to be Withdrawn Rs. ";
                        std::cin >> withdrawAmount;
                        if (withdrawAmount <= balance) {
                            balance -= withdrawAmount;
                            std::cout << "Your new available Balanced Amount is Rs. " << balance << std::endl;
                            std::cout << "Thank You!" << std::endl;
                        } else {
                            std::cout << "Insufficient Available Balance in your account." << std::endl;
                            std::cout << "Sorry!!" << std::endl;
                        }
                        std::cout << "Press any key to continue... " << std::endl;
                        std::cin.ignore();
                        std::cin.get();
                        break;
                    case 3: // Balance Inquiry
                        printSeparator();
                        std::cout << " ATM ACCOUNT STATUS " << std::endl;
                        printSeparator();
                        displayAccountDetails();
                        std::cout << "Your current available balance is Rs. " << balance << std::endl;
                        std::cout << "Thank You!" << std::endl;
                        std::cout << "Press any key to continue... " << std::endl;
                        std::cin.ignore();
                        std::cin.get();
                        break;
                    case 0: // Exit ATM
                        std::cout << "Thank You for using our ATM!" << std::endl;
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                        std::cout << "Press any key to continue... " << std::endl;
                        std::cin.ignore();
                        std::cin.get();
                        break;
                }
            } while (menuChoice!= 0);

        } else {
            // Incorrect PIN
            printSeparator();
            std::cout << " THANK YOU " << std::endl;
            printSeparator();
            std::cout << "You had made your attempt which failed!!! No More attempts allowed!! Sorry!!" << std::endl;
            printSeparator();
            std::cout << "Press any key to continue... " << std::endl;
            std::cin.ignore();
            std::cin.get();
        }

    } else if (choice == 0) {
        // Help Screen
        printSeparator();
        std::cout << " ATM ACCOUNT STATUS " << std::endl;
        printSeparator();
        std::cout << "You must have the correct pin number to access this account. See your" << std::endl;
        std::cout << "bank representative for assistance during bank opening hours" << std::endl;
        std::cout << "Thanks for, your choice today!!" << std::endl;
        printSeparator();
        std::cout << "Press any key to continue... " << std::endl;
        std::cin.ignore(); // Consume newline from previous input
        std::cin.get(); // Wait for a key press
    } else {
        std::cout << "Invalid choice. Exiting ATM." << std::endl;
    }

    return 0;
}
