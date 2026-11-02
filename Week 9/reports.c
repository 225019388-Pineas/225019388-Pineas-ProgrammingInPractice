#include <stdio.h>
#include "reports.h"

void displayWelcome(void)
{
    printf("==========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("==========================================\n");
}

void displayMainMenu(void)
{
    printf("\n==========================================\n");
    printf(" MAIN MENU\n");
    printf("==========================================\n");
    printf("1.  Capture and analyse employee salaries\n");
    printf("2.  Calculate VAT\n");
    printf("3.  Calculate gross salary\n");
    printf("4.  Calculate budget balance\n");
    printf("5.  Capture and analyse department budgets\n");
    printf("6.  Search employee by ID\n");
    printf("7.  Supplier management\n");
    printf("8.  Exit\n");
    printf("Enter choice: ");
}

void displayBudgetSummary(float revenue, float expenses, float balance)
{
    printf("\n--- Budget Summary ---\n");
    printf("Revenue:  %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance:  %.2f\n", balance);

    if (balance > 0)      printf("SURPLUS\n");
    else if (balance < 0) printf("DEFICIT\n");
    else                  printf("BALANCED\n");
}

void displaySalaryReport(float average, float highest, float lowest)
{
    printf("\n--- Salary Report ---\n");
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary:  %.2f\n", lowest);
}