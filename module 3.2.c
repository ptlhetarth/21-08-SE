//1.write a program to find the maximum number from the given array using function
#include <stdio.h>
#define MAX_SIZE 100

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int maximum = findMax(arr, size);
    printf("The maximum number in the array is: %d\n", maximum);

    return 0;
}

//2 . write a program to perform the arithmatic operations using switch case menu must be driven
#include <stdio.h>
int main() {
    char operator;
    double num1, num2, result;

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter two operands: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            if (num2!= 0) {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            } else {
                printf("Error! Division by zero.\n");
            }
            break;
        default:
            printf("Error! Invalid operator.\n");
    }
    return 0;
}

//3.write a program to find the reverse of the string using recursion
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call for the next pair
    reverseString(str, start + 1, end - 1);
}
int main() {
    char str[MAX_LENGTH];
    int length;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    length = strlen(str) - 1; // Exclude the newline character
    reverseString(str, 0, length - 1); // Adjust for 0-based indexing

    printf("Reversed string: %s", str);
    return 0;
}

// 4.write a program to take an two array as the input from the user and sort in the ascending or or descending order as per the user choice 
#include <stdio.h>
#define MAX_SIZE 100
void sortArray(int arr[], int size, int ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int arr[MAX_SIZE];
    int size, choice;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose sorting order:\n1. Ascending\n2. Descending\nEnter your choice: ");
    scanf("%d", &choice);

    sortArray(arr, size, choice == 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// 5.write a program to make the arithmetic operation of the two matrix using 2-D array
#include <stdio.h>
#define MAX_SIZE 10
int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols, choice;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("Choose the operation:\n1. Addition\n2. Subtraction\n3. Multiplication\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Addition
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = matrixA[i][j] + matrixB[i][j];
                }
            }
            printf("Result of Addition:\n");
            break;
        case 2: // Subtraction
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = matrixA[i][j] - matrixB[i][j];
                }
            }
            printf("Result of Subtraction:\n");
            break;
        case 3: // Multiplication
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < cols; k++) {
                        result[i][j] += matrixA[i][k] * matrixB[k][j];
                    }
                }
            }
            printf("Result of Multiplication:\n");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Print the result matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 6. WAP Find out length of string without using inbuilt function
#include <stdio.h>

int string_length(char *str) {
    int length = 0;
    while (str[length]!= '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str); // Using scanf to read string, it stops at whitespace

    int length = string_length(str);
    printf("Length of the string is: %d\n", length);

    return 0;
}

// 7. WAP to reverse a string and check that the string is palindrome or not
#include <stdio.h>
#include <string.h> // For strlen (used only for demonstration, can be replaced by custom length function)

// Function to reverse a string
void reverse_string(char *str) {
    int length = strlen(str); // Using strlen for simplicity, can use custom_length
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int length = strlen(str); // Using strlen for simplicity
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // It is a palindrome
}

int main() {
    char original_str[100];
    char temp_str[100]; // To store a copy for reversal without altering original

    printf("Enter a string: ");
    scanf("%s", original_str);

    // Make a copy for reversal
    strcpy(temp_str, original_str);

    // Check if palindrome
    if (is_palindrome(original_str)) {
        printf("The string '%s' is a palindrome.\n", original_str);
    } else {
        printf("The string '%s' is not a palindrome.\n", original_str);
    }

    // Reverse the string
    reverse_string(temp_str);
    printf("Reversed string: %s\n", temp_str);

    return 0;
}


// 8.  Write a program of structure employee that provides the following
// information -print and display empno, empname, address and age
#include <stdio.h>
#include <string.h> // For strcpy

// Define the Employee structure
struct Employee {
    int empno;
    char empname[50];
    char address[100];
    int age;
};

int main() {
    // Declare an employee variable
    struct Employee emp1;

    // Assign values to the employee's information
    emp1.empno = 101;
    strcpy(emp1.empname, "Alice Smith");
    strcpy(emp1.address, "123 Main St, Anytown");
    emp1.age = 30;

    // Print and display the employee's information
    printf("Employee Information:\n");
    printf("Employee Number: %d\n", emp1.empno);
    printf("Employee Name: %s\n", emp1.empname);
    printf("Address: %s\n", emp1.address);
    printf("Age: %d\n", emp1.age);

    return 0;
}

//9.same program as the above 
//10.  WAP to show difference between Structure and Union.
#include <stdio.h>
#include <string.h> // For strcpy

// Define a Structure
struct Student_Structure {
    int id;
    char name[20];
    float marks;
};

// Define a Union
union Student_Union {
    int id;
    char name[20];
    float marks;
};

int main() {
    // --- Demonstrating Structure ---
    struct Student_Structure s_struct;

    printf("--- Structure Example ---\n");

    // Assign values to structure members
    s_struct.id = 1;
    strcpy(s_struct.name, "Alice");
    s_struct.marks = 85.5;

    // Access and print structure members
    printf("Structure:\n");
    printf("ID: %d\n", s_struct.id);
    printf("Name: %s\n", s_struct.name);
    printf("Marks: %.2f\n", s_struct.marks);
    printf("Size of Structure: %lu bytes\n", sizeof(struct Student_Structure));
    // Note: The size will be the sum of sizes of all members (plus padding)

    printf("\n--- Union Example ---\n");
    // --- Demonstrating Union ---
    union Student_Union s_union;

    // Assign value to id member
    s_union.id = 2;
    printf("Union after assigning ID:\n");
    printf("ID: %d\n", s_union.id);
    // If you try to access name or marks now, they might have garbage values
    // printf("Name: %s\n", s_union.name); // Potentially garbage
    // printf("Marks: %.2f\n", s_union.marks); // Potentially garbage

    // Assign value to name member (this will overwrite 'id')
    strcpy(s_union.name, "Bob");
    printf("\nUnion after assigning Name (ID might be corrupted):\n");
    printf("Name: %s\n", s_union.name);
    // Now, id will likely have a garbage value or a reinterpretation of 'Bob' as an integer
    // depending on system architecture and union memory layout.
    // marks will also be garbage.
    printf("ID: %d (corrupted)\n", s_union.id);
    // printf("Marks: %.2f\n", s_union.marks); // Potentially garbage

    // Assign value to marks member (this will overwrite 'name' and 'id')
    s_union.marks = 92.3;
    printf("\nUnion after assigning Marks (Name and ID might be corrupted):\n");
    printf("Marks: %.2f\n", s_union.marks);
    // Now, name and id will likely have garbage values.
    // printf("ID: %d (corrupted)\n", s_union.id); // Potentially garbage
    // printf("Name: %s (corrupted)\n", s_union.name); // Potentially garbage

    printf("Size of Union: %lu bytes\n", sizeof(union Student_Union));
    // Note: The size will be the size of its largest member.
    // In this case, 'name' (char[20]) is likely the largest.

    printf("\nDifferences:\n");
    printf("1. Memory Allocation:\n");
    printf(" - Structure allocates memory for all its members separately. Size = sum of sizes of members (plus padding).\n");
    printf(" - Union allocates memory for only its largest member. Size = size of the largest member.\n");
    printf("2. Data Storage:\n");
    printf(" - Structure members can hold values simultaneously.\n");
    printf(" - Union members share the same memory location, so only one member can hold a value at any given time.\n");
    printf("3. Access:\n");
    printf(" - All members of a structure can be accessed at any time.\n");
    printf(" - Only the last assigned member of a union holds a valid value; accessing others leads to undefined behavior.\n");

    return 0;
}