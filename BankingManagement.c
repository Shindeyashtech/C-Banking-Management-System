#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void showMenu();
void deposit(int amount);
void withdraw(int amount);
void getPreviousTransaction();
int isValidAccountNumber(char *accountNumber);
int isValidPin(int pin);

// Global variables for account balance and previous transaction
int balance = 0;
int previousTransaction = 0;

int main() {
    printf("\nWelcome to Our Bank\n");

    char accountNumber[20];
    int pin;

    while (1) {
        printf("====================================\n");
        printf("Enter Your Account Number : ");
        fgets(accountNumber, sizeof(accountNumber), stdin);
        accountNumber[strcspn(accountNumber, "\n")] = 0; // Remove newline character

        // Dummy check for account number
        if (!isValidAccountNumber(accountNumber)) {
            printf("Error: Incorrect account number. Please try again.\n");
            continue;
        }

        printf("Enter Your PIN : ");
        scanf("%d", &pin);
        getchar(); // Consume the newline character after scanf

        // Dummy check for pin
        if (!isValidPin(pin)) {
            printf("Error: Incorrect PIN. Please try again.\n");
            continue;
        }

        // If PIN is correct, show customer name and prompt to continue
        printf("====================================\n");
        printf("Welcome, Yash Shinde!\n");
        printf("Press Enter to continue...");
        getchar(); // Wait for Enter key press

        showMenu();
    }

    return 0;
}

// Dummy validation for account number
int isValidAccountNumber(char *accountNumber) {
    // Dummy validation logic, replace with actual validation
    return strcmp(accountNumber, "12345678") == 0;
}

// Dummy validation for pin
int isValidPin(int pin) {
    // Dummy validation logic, replace with actual validation
    return pin == 1234;
}

// Function to deposit money
void deposit(int amount) {
    if (amount > 0) {
        balance += amount;
        previousTransaction = amount;
    }
}

// Function to withdraw money
void withdraw(int amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        previousTransaction = -amount;
        printf("Withdrawal Successful: %d\n", amount);
    } else {
        printf("Error: Insufficient balance. Your balance is %d\n", balance);
    }
}

// Function to view the previous transaction
void getPreviousTransaction() {
    if (previousTransaction > 0) {
        printf("Deposited: %d\n", previousTransaction);
    } else if (previousTransaction < 0) {
        printf("Withdrawn: %d\n", -previousTransaction);
    } else {
        printf("No transaction occurred\n");
    }
}

// Function to print the menu options
void printMenu() {
    printf("A. Check Balance\n");
    printf("B. Deposit\n");
    printf("C. Withdraw\n");
    printf("D. View Previous Transaction\n");
    printf("E. Exit\n");
}

// Function to show the menu and handle user input
void showMenu() {
    char option;
    do {
        printf("======================================\n");
        printMenu();
        printf("======================================\n");
        printf("Enter Your Choice: ");
        scanf(" %c", &option); // Note the space before %c to consume any leftover newline character
        getchar(); // Consume the newline character

        switch (option) {
            case 'A':
            case 'a':
                printf("======================================\n");
                printf("Your Balance: %d\n", balance);
                printf("======================================\n");
                break;

            case 'B':
            case 'b':
                printf("======================================\n");
                printf("Enter Deposit Amount: ");
                int depositAmount;
                scanf("%d", &depositAmount);
                deposit(depositAmount);
                printf("Deposit Successful\n");
                printf("======================================\n");
                break;

            case 'C':
            case 'c':
                printf("======================================\n");
                printf("Enter Withdrawal Amount: ");
                int withdrawalAmount;
                scanf("%d", &withdrawalAmount);
                withdraw(withdrawalAmount);
                printf("======================================\n");
                break;

            case 'D':
            case 'd':
                printf("======================================\n");
                getPreviousTransaction();
                printf("======================================\n");
                break;

            case 'E':
            case 'e':
                printf("Thank you for using our services!\n");
                break;

            default:
                printf("Invalid Option! Please enter again.\n");
                break;
        }
    } while (option != 'E' && option != 'e');
}
