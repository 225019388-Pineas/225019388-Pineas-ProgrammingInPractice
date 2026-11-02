#include <stdio.h>

int main() {

    
    double revenue;
    double expenses;
    double balance;




    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("----------------------------\n\n");



    printf("Enter total revenue: ");
    scanf("%lf", &revenue);




    printf("Enter total expenses: ");
    scanf("%lf", &expenses);



    balance = revenue - expenses;

    printf("\n--- Municipal Budget Summary ---\n");
    printf("Revenue:  N$%.2f\n", revenue);
    printf("Expenses: N$%.2f\n", expenses);
    printf("Balance:  N$%.2f\n", balance);

    return 0;
}