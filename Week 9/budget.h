#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 10

void captureBudgets(float budgets[], int n);
void displayBudgets(float budgets[], int n);
float calculateVAT(float amount);
float calculateBudget(float revenue, float expenses);
float calculateTotal(float arr[], int n);
void sortBudgetsAscending(float budgets[], int n);

#endif