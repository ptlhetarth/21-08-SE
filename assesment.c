#include <stdio.h> // Required for input/output functions like printf and scanf
#include <string.h> // Required for string functions like strcmp (though not strictly used in this simplified version)

int main() {
    // Variables to hold user's choice, quantity, and the running total amount
    int choice;
    int quantity;
    int total_bill = 0; // Initialize total bill to 0
    char place_more_orders = 'y'; // Character to decide if user wants to order more

    // Loop to keep taking orders as long as the user wants to
    while (place_more_orders == 'y' || place_more_orders == 'Y') {
        // Display the menu to the user
        printf("1.Pizza price = 180rs/pcs\n");
        printf("2.Burger price = 100rs/pcs\n");
        printf("3.Dosa price = 120rs/pcs\n");
        printf("4.Idli price = 50rs/pcs\n");

        printf("Please Enter your choose... :");
        scanf("%d", &choice); // Read the user's choice (1, 2, 3, or 4)

        // Declare amount for the current item, initialize to 0
        int item_amount = 0;
        char item_name[20]; // To store the name of the selected item

        // Use a switch statement to handle different choices
        switch (choice) {
            case 1:
                strcpy(item_name, "Pizza"); // Copy "Pizza" into item_name
                item_amount = 180; // Set base price for Pizza
                break;
            case 2:
                strcpy(item_name, "Burger");
                item_amount = 100;
                break;
            case 3:
                strcpy(item_name, "Dosa");
                item_amount = 120;
                break;
            case 4:
                strcpy(item_name, "Idli");
                item_amount = 50;
                break;
            default:
                // If user enters an invalid choice, tell them and skip this order
                printf("Invalid choice. Please select from 1 to 4.\n");
                // Clear any leftover input characters to prevent issues in next loop
                while (getchar()!= '\n');
                continue; // Skip the rest of this loop iteration and start again
        }

        // Inform the user about their selection
        printf("You have selected %s.\n", item_name);

        printf("Enter the quantity :");
        scanf("%d", &quantity); // Read the quantity

        // Calculate the total amount for this specific item
        item_amount = item_amount * quantity;
        printf("Amount : %d\n", item_amount);

        // Add this item's amount to the overall total bill
        total_bill += item_amount;
        printf("Total Amount is = %d\n", total_bill);

        // Ask the user if they want to place more orders
        printf("Do you want place more orders? y & n :");
        // Clear any leftover input characters (especially the newline from previous scanf)
        while (getchar()!= '\n');
        scanf(" %c", &place_more_orders); // Read 'y' or 'n'. Space before %c handles newline

        // If they want to order more, print the menu separator like in the example
        if (place_more_orders == 'y' || place_more_orders == 'Y') {
            printf("-------- Manu --------\n");
        }
       else
       {
           printf("thank you for ordering");
       }
    } // End of while loop

    return 0; // Indicate that the program finished successfully
}