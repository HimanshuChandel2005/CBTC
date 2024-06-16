#include <stdio.h>
#include <string.h>

struct BankAccount {
    int accountNumber;
    char accountType[50];
    float balance;
};

struct BankAccount createAccount() {
    struct BankAccount account;

    printf("Enter account number: ");
    scanf("%d", &account.accountNumber);

    printf("Enter account type (Savings/Current/Others): ");
    scanf("%s", account.accountType);

    printf("Enter initial balance: ");
    scanf("%f", &account.balance);

    return account;
}

void deposit(struct BankAccount *account) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    account->balance += amount; // Add amount to the balance

    printf("Deposit successful!\n");
}

void withdraw(struct BankAccount *account) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > account->balance) {
        printf("Insufficient balance!\n");
    } else {
        account->balance -= amount; // Subtract amount from the balance
        printf("Withdrawal successful!\n");
    }
}

void checkBalance(struct BankAccount account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Type: %s\n", account.accountType);
    printf("Balance: %.2f\n", account.balance);
}

float calculateInterest(struct BankAccount account) {
    float interestRate;

    if (strcmp(account.accountType, "Savings") == 0) {
        interestRate = 0.05;
    } else if (strcmp(account.accountType, "Current") == 0) {
        interestRate = 0.02;
    } else {
        interestRate = 0.01;
    }

    return account.balance * interestRate;
}

int main() {
    struct BankAccount accounts[10]; 
    int numAccounts = 0; 

    int choice, accountIndex;

    do {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numAccounts < 10) {
                    accounts[numAccounts] = createAccount(); 
                    numAccounts++;
                    printf("Account created successfully!\n");
                } else {
                    printf("Maximum number of accounts reached!\n");
                }
                break;
            case 2:
                printf("Enter account index: ");
                scanf("%d", &accountIndex);
                if (accountIndex >= 0 && accountIndex < numAccounts) {
                    deposit(&accounts[accountIndex]);
                } else {
                    printf("Invalid account index!\n");
                }
                break;
            case 3:
                printf("Enter account index: ");
                scanf("%d", &accountIndex);
                if (accountIndex >= 0 && accountIndex < numAccounts) {
                    withdraw(&accounts[accountIndex]);
                } else {
                    printf("Invalid account index!\n");
                }
                break;
            case 4:
                printf("Enter account index: ");
                scanf("%d", &accountIndex);
                if (accountIndex >= 0 && accountIndex < numAccounts) {
                    checkBalance(accounts[accountIndex]);
                } else {
                    printf("Invalid account index!\n");
                }
                break;
            case 5:
                printf("Enter account index: ");
                scanf("%d", &accountIndex);
                if (accountIndex >= 0 && accountIndex < numAccounts) {
                    float interest = calculateInterest(accounts[accountIndex]);
                    printf("Interest earned: %.2f\n", interest);
                } else {
                    printf("Invalid account index!\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6); 

    return 0;
}
