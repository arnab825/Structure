#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store customer data
struct customer
{
    char name[100];
    int accountNumber;
    char accountType[100];
    int balance;
    char address[100];
   long int phoneNumber;
    char dateOfBirth[100];
};

// function to add a customer
void addCustomer(struct customer *c, int *n)
{
    printf("Enter customer name: \n");
    fflush(stdin);
    gets(c[*n].name);
    fflush(stdin);
    printf("Enter account number: \n");
    scanf("%d", &c[*n].accountNumber);
    printf("Enter account type: \n");
    scanf("%s", c[*n].accountType);
    printf("Enter balance: \n");
    scanf("%d", &c[*n].balance);
    printf("Enter address: \n");
    scanf("%s", c[*n].address);
    printf("Enter phone number: \n");
    scanf("%ld", &c[*n].phoneNumber);
    printf("Enter date of birth: \n");
    scanf("%s", c[*n].dateOfBirth);
    *n = *n + 1;
}

// function to display all customers
void displayAllCustomers(struct customer *c, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Customer name: %s\n", c[i].name);
        printf("Account number: %d\n", c[i].accountNumber);
        printf("Account type: %s\n", c[i].accountType);
        printf("Balance: %d\n", c[i].balance);
        printf("Address: %s\n", c[i].address);
        printf("Phone number: %ld\n", c[i].phoneNumber);
        printf("Date of birth: %s\n", c[i].dateOfBirth);
    }
}

// function to search a customer
void searchCustomer(struct customer *c, int n)
{
    int i, accountNumber;
    printf("Enter account number to search: ");
    scanf("%d", &accountNumber);
    for (i = 0; i < n; i++)
    {
        if (c[i].accountNumber == accountNumber)
        {
            printf("Customer name: %s\n", c[i].name);
            printf("Account number: %d\n", c[i].accountNumber);
            printf("Account type: %s\n", c[i].accountType);
            printf("Balance: %d\n", c[i].balance);
            printf("Address: %s\n", c[i].address);
            printf("Phone number: %ld\n", c[i].phoneNumber);
            printf("Date of birth: %s\n", c[i].dateOfBirth);
            return;
        }
    }
    printf("Account number not found");
}
//function to calculate the amount 
void amountOfBalance(struct customer *c,int n)
{
    int amt,i;
    printf("Enter the amount to be searched:\n");
    scanf("%d",&amt);
    for(i=0;i<n;i++)
    {
        amt=amt+c[i].balance;
    }
    printf("Balance: %d\n", amt);

}

// function to update a customer
void updateCustomer(struct customer *c, int n)
{
    int i,amt, accountNumber;
    printf("Enter account number to update: ");
    scanf("%d", &accountNumber);
    for (i = 0; i < n; i++)
    {
        if (c[i].accountNumber == accountNumber)
        {
            printf("Customer name: %s\n", c[i].name);
            printf("Account number: %d\n", c[i].accountNumber);
            printf("Account type: %s\n", c[i].accountType);
            amountOfBalance(c,n);
            printf("Address: %s\n", c[i].address);
            printf("Phone number: %ld\n", c[i].phoneNumber);
            printf("Date of birth: %s\n", c[i].dateOfBirth);
            
            return;
        }
    }
    printf("Account number not found");
}

// function to delete a customer
void deleteCustomer(struct customer *c, int *n)
{
    int i, accountNumber;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);
    for (i = 0; i < *n; i++)
    {
        if (c[i].accountNumber == accountNumber)
        {
            c[i] = c[*n - 1];
            *n = *n - 1;
            return;
        }
        printf("Account Number has been deleted");
    }
    printf("Account number not found");
}

// main function

int main()
{
    struct customer c[100];
    int n = 0, choice;
    while (1)
    {
        printf("1. Add customer\n");
        printf("2. Display all customers\n");
        printf("3. Search customer\n");
        printf("4. Update customer\n");
        printf("5. Delete customer\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addCustomer(c, &n);
            break;
        case 2:
            displayAllCustomers(c, n);
            break;
        case 3:
            searchCustomer(c, n);
            break;
        case 4:
            updateCustomer(c, n);
            break;
        case 5:
            deleteCustomer(c, &n);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}

