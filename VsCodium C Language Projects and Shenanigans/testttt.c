#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 100

// Transaction structure
typedef struct {
    int id;
    char type[20];
    float amount;
    float balance;
    char date[50];
} Transaction;

// Account structure
typedef struct {
    float balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} Account;

// Function prototypes
void initAccount(Account *acc, float initialBalance);
void deposit(Account *acc, float amount);
void withdraw(Account *acc, float amount);
void displayBalance(Account *acc);
void displayTransactionHistory(Account *acc);
void addTransaction(Account *acc, const char *type, float amount);
void getCurrentTime(char *buffer);
void clearInputBuffer();

int main() {
    Account account;
    int choice;
    float amount;
    
    // Initialize account with starting balance
    initAccount(&account, 1000.0);
    
    printf("===========================================\n");
    printf("      WELCOME TO BANKING SYSTEM\n");
    printf("===========================================\n\n");
    
    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Transaction History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        
        switch (choice) {
            case 1:
                displayBalance(&account);
                break;
                
            case 2:
                printf("\nEnter amount to deposit: $");
                if (scanf("%f", &amount) != 1) {
                    clearInputBuffer();
                    printf("Invalid amount!\n");
                    break;
                }
                deposit(&account, amount);
                break;
                
            case 3:
                printf("\nEnter amount to withdraw: $");
                if (scanf("%f", &amount) != 1) {
                    clearInputBuffer();
                    printf("Invalid amount!\n");
                    break;
                }
                withdraw(&account, amount);
                break;
                
            case 4:
                displayTransactionHistory(&account);
                break;
                
            case 5:
                printf("\nThank you for using our banking system!\n");
                printf("Goodbye!\n");
                return 0;
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

// Initialize account with starting balance
void initAccount(Account *acc, float initialBalance) {
    acc->balance = initialBalance;
    acc->transactionCount = 0;
    addTransaction(acc, "Initial Balance", initialBalance);
}

// Deposit algorithm
void deposit(Account *acc, float amount) {
    if (amount <= 0) {
        printf("\n[ERROR] Amount must be positive!\n");
        return;
    }
    
    acc->balance += amount;
    addTransaction(acc, "Deposit", amount);
    
    printf("\n[SUCCESS] Deposited: $%.2f\n", amount);
    printf("New Balance: $%.2f\n", acc->balance);
}

// Withdraw algorithm
void withdraw(Account *acc, float amount) {
    if (amount <= 0) {
        printf("\n[ERROR] Amount must be positive!\n");
        return;
    }
    
    if (amount > acc->balance) {
        printf("\n[ERROR] Insufficient funds!\n");
        printf("Current Balance: $%.2f\n", acc->balance);
        return;
    }
    
    acc->balance -= amount;
    addTransaction(acc, "Withdrawal", amount);
    
    printf("\n[SUCCESS] Withdrawn: $%.2f\n", amount);
    printf("New Balance: $%.2f\n", acc->balance);
}

// Display current balance
void displayBalance(Account *acc) {
    printf("\n===========================================\n");
    printf("         CURRENT BALANCE\n");
    printf("===========================================\n");
    printf("         $%.2f\n", acc->balance);
    printf("===========================================\n");
}

// Display transaction history
void displayTransactionHistory(Account *acc) {
    printf("\n===========================================\n");
    printf("       TRANSACTION HISTORY\n");
    printf("===========================================\n");
    
    if (acc->transactionCount == 0) {
        printf("No transactions yet.\n");
        return;
    }
    
    for (int i = acc->transactionCount - 1; i >= 0; i--) {
        Transaction t = acc->transactions[i];
        printf("\n[%d] %s\n", t.id, t.type);
        printf("    Amount: $%.2f\n", t.amount);
        printf("    Balance: $%.2f\n", t.balance);
        printf("    Date: %s\n", t.date);
        printf("-------------------------------------------\n");
    }
}

// Add transaction to history
void addTransaction(Account *acc, const char *type, float amount) {
    if (acc->transactionCount >= MAX_TRANSACTIONS) {
        printf("\n[WARNING] Transaction history full!\n");
        return;
    }
    
    Transaction *t = &acc->transactions[acc->transactionCount];
    t->id = acc->transactionCount + 1;
    strcpy(t->type, type);
    t->amount = amount;
    t->balance = acc->balance;
    getCurrentTime(t->date);
    
    acc->transactionCount++;
}

// Get current date and time
void getCurrentTime(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 50, "%Y-%m-%d %H:%M:%S", t);
}

// Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}