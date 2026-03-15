// module 3.1
//write a program to display the information of the user using the printf function 

#include <stdio.h>

int main() {
    printf("Name: John Doe\n");
    printf("Birth Date: 01/01/2000\n");
    printf("Age: 26\n"); // Assuming current date is 2026
    printf("Address: 123 Main Street, Anytown, USA\n");
    return 0;
}


//2.write a program to demonstrate the calculator 
#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter operator (+, -, *, /, %%): ");
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
        case '%': // Modulo operator works only with integers
            // Cast doubles to integers for modulo
            if ((int)num2!= 0) {
                 result = (int)num1 % (int)num2;
                 printf("%d %% %d = %d\n", (int)num1, (int)num2, (int)result);
            } else {
                printf("Error! Modulo by zero.\n");
            }
            break;
        default:
            printf("Error! Invalid operator.\n");
    }
    return 0;
}


// 3.write a program to find the area of circle , rectangle and triangle 
#include <stdio.h>

#define PI 3.14159

int main() {
    double radius, length, width, base, height;
    double area_circle, area_rectangle, area_triangle;

    // Area of Circle
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    area_circle = PI * radius * radius;
    printf("Area of Circle: %.2lf\n", area_circle);

    // Area of Rectangle
    printf("\nEnter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);
    area_rectangle = length * width;
    printf("Area of Rectangle: %.2lf\n", area_rectangle);

    // Area of Triangle
    printf("\nEnter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    area_triangle = 0.5 * base * height;
    printf("Area of Triangle: %.2lf\n", area_triangle);

    return 0;
}

// 4.write a program to find the simple interest 
#include <stdio.h>

int main() {
    double principal, rate, time, simple_interest;

    printf("Enter Principal Amount: ");
    scanf("%lf", &principal);

    printf("Enter Rate of Interest (in %%): ");
    scanf("%lf", &rate);

    printf("Enter Time (in years): ");
    scanf("%lf", &time);

    simple_interest = (principal * rate * time) / 100;

    printf("Simple Interest = %.2lf\n", simple_interest);

    return 0;
}

//5. write a program to convert the years into the days and days into the years 
#include <stdio.h>

int main() {
    int years, days;

    // Years to Days
    printf("Enter years to convert to days: ");
    scanf("%d", &years);
    days = years * 365; // Simple conversion, ignoring leap years for simplicity
    printf("%d years is approximately %d days.\n", years, days);

    // Days to Years
    printf("\nEnter days to convert to years: ");
    scanf("%d", &days);
    years = days / 365; // Integer division
    printf("%d days is approximately %d years.\n", days, years);

    return 0;
}

//6.write a program to check if the given year is a leap year or not
#include <stdio.h>

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100!= 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}

/* module 3.2 
1. write a program to make the simple calculator this program is simple as  the previous module's question no 2 so the code 
will also be the same */

//2. write a program to swap the two numbers without using the third variable 
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter value for a: ");
    scanf("%d", &a);
    printf("Enter value for b: ");
    scanf("%d", &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    a = a + b; // a now holds the sum of original a and b
    b = a - b; // b now holds original a ( (a+b) - b = a )
    a = a - b; // a now holds original b ( (a+b) - a = b )

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}

//3. write a program to find the even or odd number using the ternary operator 
#include <stdio.h>

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    (num % 2 == 0)? printf("%d is Even.\n", num) : printf("%d is Odd.\n", num);

    return 0;
}

/*4. WAP to show (Monday to Sunday using switch case & Vowel or Consonant using switch case)
Part A: Monday to Sunday using switch case*/
#include <stdio.h>

int main() {
    int day_num;

    printf("Enter a number (1-7) for the day of the week: ");
    scanf("%d", &day_num);

    switch (day_num) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid number. Please enter a number between 1 and 7.\n");
            break;
    }

    return 0;
}

//Part B: Vowel or Consonant using switch case
#include <stdio.h>
#include <ctype.h> // For toupper()

int main() {
    char ch;

    printf("Enter an alphabet: ");
    scanf(" %c", &ch); // Space before %c to consume any leftover newline

    ch = toupper(ch); // Convert to uppercase for easier comparison

    if (ch >= 'A' && ch <= 'Z') { // Check if it's an alphabet
        switch (ch) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                printf("%c is a Vowel.\n", ch);
                break;
            default:
                printf("%c is a Consonant.\n", ch);
                break;
        }
    } else {
        printf("%c is not an alphabet.\n", ch);
    }

    return 0;
}

/*Looping programs:
1. WAP to print 972 to 897 using for loop
2. WAP to take 10 no. Input from user and find out …
3. How many Even numbers are there
4. How many odd numbers are there
5. Sum of even numbers
6. Sum of odd numbers WAP to print table up to given numbers 
*/
//Part A: WAP to print 972 to 897 using for loop
#include <stdio.h>

int main() {
    printf("Numbers from 972 to 897:\n");
    for (int i = 972; i >= 897; i--) {
        printf("%d ", i);
        if ((972 - i + 1) % 10 == 0) { // Print 10 numbers per line for readability
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}

//Part B: WAP to take 10 no. Input from user and find out Even/Odd counts and sums
#include <stdio.h>

int main() {
    int num, i;
    int even_count = 0, odd_count = 0;
    int sum_even = 0, sum_odd = 0;

    printf("Enter 10 integers:\n");

    for (i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        if (num % 2 == 0) {
            even_count++;
            sum_even += num;
        } else {
            odd_count++;
            sum_odd += num;
        }
    }

    printf("\nResults:\n");
    printf("Number of Even numbers: %d\n", even_count);
    printf("Number of Odd numbers: %d\n", odd_count);
    printf("Sum of Even numbers: %d\n", sum_even);
    printf("Sum of Odd numbers: %d\n", sum_odd);

    return 0;
}

//Part C: WAP to print table up to given numbers
#include <stdio.h>

int main() {
    int num;

    printf("Enter a number to print its multiplication table: ");
    scanf("%d", &num);

    printf("Multiplication Table of %d:\n", num);
    for (int i = 1; i <= 10; i++) { // Typically tables go up to 10
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}

//module 3.3
//1. WAP to find the factorial of a number
#include <stdio.h>

long long factorial(int n) {
    if (n < 0) {
        return -1; // Indicate error for negative input
    }
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    long long result = factorial(num);
    if (result!= -1) {
        printf("Factorial of %d = %lld\n", num, result);
    } else {
        printf("Factorial is not defined for negative numbers.\n");
    }

    return 0;
}

//2.write a program to find the fibonacci series of the given number by the user 
#include <stdio.h>

int main() {
    int n, a = 0, b = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        printf("%d, ", a);
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    printf("\n");

    return 0;
}

//3. write a program to display the number in the reverse order 
#include <stdio.h>

int main() {
    int num, reversed_num = 0, remainder;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Store original number for output
    int original_num = num;

    while (num!= 0) {
        remainder = num % 10;
        reversed_num = reversed_num * 10 + remainder;
        num /= 10;
    }

    printf("Original number = %d\n", original_num);
    printf("Reversed number = %d\n", reversed_num);

    return 0;
}

//4.write a program to find the maxium number 
#include <stdio.h>
#include <math.h> // For abs()

int main() {
    int num, digit, max_digit = -1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Handle negative numbers by taking absolute value
    int temp_num = abs(num);
    if (temp_num == 0) {
        max_digit = 0; // Max digit in 0 is 0
    }

    while (temp_num > 0) {
        digit = temp_num % 10;
        if (digit > max_digit) {
            max_digit = digit;
        }
        temp_num /= 10;
    }

    printf("From number %d, the maximum digit is %d\n", num, max_digit);

    return 0;
}

//5. write a program to make the summation of the given number 
#include <stdio.h>
#include <math.h> // For abs()

int main() {
    int num, sum_digits = 0, digit;

    printf("Enter an integer: ");
    scanf("%d", &num);

    int temp_num = abs(num); // Work with absolute value for digit sum

    if (temp_num == 0) {
        sum_digits = 0;
    } else {
        while (temp_num > 0) {
            digit = temp_num % 10;
            sum_digits += digit;
            temp_num /= 10;
        }
    }
    printf("Summation of digits of %d = %d\n", num, sum_digits);
    // If the expected output -11 for 1523 is intended to be (1+5+2+3)*(-1)
    // then simply: printf("Summation of digits of %d = %d\n", num, -sum_digits);
    // But the problem phrasing is "summation of given number" and example is -11 for 1523
    // which implies (1+5+2+3) = 11, then some operation leads to -11. This is ambiguous.
    // Standard interpretation is sum of digits.
    return 0;
}

/*6.Write a program you have to make a summation of first and last Digit. (E.g.,
1234 Ans: -5)*/

#include <stdio.h>
#include <math.h> // For abs()

int main() {
    int num, first_digit, last_digit;

    printf("Enter an integer: ");
    scanf("%d", &num);

    int temp_num = abs(num); // Work with absolute value

    if (temp_num == 0) {
        first_digit = 0;
        last_digit = 0;
    } else {
        last_digit = temp_num % 10; // Get the last digit

        // Get the first digit
        first_digit = temp_num;
        while (first_digit >= 10) {
            first_digit /= 10;
        }
    }

    int sum_first_last = first_digit + last_digit;
    printf("For number %d, first digit = %d, last digit = %d\n", num, first_digit, last_digit);
    printf("Sum of first and last digit = %d\n", sum_first_last);
    // If -5 for 1234 means (1+4)*(-1), then: printf("Sum of first and last digit = %d\n", -sum_first_last);
    // This is also ambiguous.

    return 0;
}

/*7. part A: write a program to print the given below pattern
1
10
101
1010
10101*/
#include <stdio.h>
int main() {
    int rows = 5; // Number of rows for the pattern

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            if (j % 2 != 0) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}

/* part B : write a program print the given below pattern
A
BC
DEF
GHIJ
KLMNO*/
#include <stdio.h>
int main() {
    char letter = 'A'; // Starting letter

    for (int i = 1; i <= 5; i++) { // Number of rows
        for (int j = 1; j <= i; j++) { // Number of letters in each row
            printf("%c", letter);
            letter++; // Move to the next letter
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}

/* part C : write a program to print the given below pattern
    *
   ***
  *****
 *******
*********
*/
#include<stdio.h>
int main()
{
    int rows = 5; // Number of rows for the pattern

    for (int i = 1; i <= rows; i++) {
        // Print spaces
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}

/* part D : write a program to print the given below pattern
*
**
***
****
*****
****
***
*
**/
#include <stdio.h>
int main()
{
    int rows = 5; // Number of rows for the upper part of the pattern

    // Print the upper part of the pattern
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the lower part of the pattern
    for (int i = rows - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

/* part E : write a program to print the given below pattern
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15*/
#include <stdio.h>
int main()
{
    int rows = 5; // Number of rows for the pattern
    int num = 1; // Starting number

    for (int i = 1; i <= rows; i++) { // Loop through each row
        for (int j = 1; j <= i; j++) { // Loop through each column in the current row
            printf("%d ", num);
            num++; // Increment the number for the next print
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}

/* part F : write a program to print the given below pattern
A
AB
ABC
ABCD
ABCDE*/
#include <stdio.h>
int main()
{
    int rows = 5; // Number of rows for the pattern

    for (int i = 1; i <= rows; i++) { // Loop through each row
        for (int j = 1; j <= i; j++) { // Loop through each column in the current row
            printf("%c", 'A' + j - 1);
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}
