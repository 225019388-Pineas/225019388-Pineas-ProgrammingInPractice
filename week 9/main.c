#include <stdio.h>
#include "main.h"
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"
#include "suppliers.h"

int main(void)
{
    float salaries[MAX_EMPLOYEES];
    float budgets[MAX_BUDGETS];
    int employeeIDs[] = {101, 102, 103, 104, 105};

    int choice;

    displayWelcome();

    do {
        displayMainMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {

        case 1: {
            captureSalaries(salaries, MAX_EMPLOYEES);
            displaySalaries(salaries, MAX_EMPLOYEES);
            displaySalaryReport(
                calculateAverage(salaries, MAX_EMPLOYEES),
                findHighest(salaries, MAX_EMPLOYEES),
                findLowest(salaries, MAX_EMPLOYEES));
            searchSalary(salaries, MAX_EMPLOYEES);
            break;
        }

        case 2: {
            float amount = readFloat("\nEnter amount: ");
            printf("VAT (15%%): %.2f\n", calculateVAT(amount));
            break;
        }

        case 3: {
            float basic     = readFloat("\nEnter basic salary: ");
            float housing   = readFloat("Enter housing allowance: ");
            float transport = readFloat("Enter transport allowance: ");
            printf("Gross Salary: %.2f\n",
                   calculateSalary(basic, housing, transport));
            break;
        }

        case 4: {
            float revenue  = readFloat("\nEnter revenue: ");
            float expenses = readFloat("Enter expenses: ");
            float balance  = calculateBudget(revenue, expenses);
            displayBudgetSummary(revenue, expenses, balance);
            break;
        }

        case 5: {
            captureBudgets(budgets, MAX_BUDGETS);
            displayBudgets(budgets, MAX_BUDGETS);
            printf("\nTotal budget: %.2f\n",
                   calculateTotal(budgets, MAX_BUDGETS));
            printf("Average budget: %.2f\n",
                   calculateAverage(budgets, MAX_BUDGETS));

            sortBudgetsAscending(budgets, MAX_BUDGETS);
            printf("\n--- Budgets sorted lowest to highest ---\n");
            displayBudgets(budgets, MAX_BUDGETS);
            break;
        }

        case 6: {
            int id  = readInt("\nEnter employee ID: ");
            int pos = searchEmployee(id, employeeIDs, 5);
            if (pos != -1)
                printf("Employee found at position %d.\n", pos);
            else
                printf("Employee not found.\n");
            break;
        }

        case 7:
            runSupplierModule();
            break;

        case 8:
            printf("\nGoodbye.\n");
            break;

        default:
            printf("\nInvalid choice. Please enter 1-8.\n");
        }

    } while (choice != 8);

    return 0;
}