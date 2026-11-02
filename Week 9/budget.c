#include <stdio.h>
#include "budget.h"

void captureBudgets(float budgets[], int n)
{
    printf("\n--- Capture %d Department Budgets ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }
}

void displayBudgets(float budgets[], int n)
{
    printf("\n--- Department Budgets ---\n");
    for (int i = 0; i < n; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }
}

float calculateVAT(float amount)
{
    return amount * 0.15;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

float calculateTotal(float arr[], int n)
{
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

void sortBudgetsAscending(float budgets[], int n)
{
    float temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }
}