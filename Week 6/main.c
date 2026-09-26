#include <stdio.h>
#include <string.h>

#define MAX_SALARIES 50
#define MAX_BUDGETS 10
#define MAX_REGISTRATIONS 20
#define REG_LENGTH 20

/* ============================================================
   PART A: EMPLOYEE SALARIES
   ============================================================ */
void captureSalaries(float salaries[], int n) {
    printf("\n--- Capture %d Employee Salaries ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }
}

void displaySalaries(float salaries[], int n) {
    printf("\n--- Employee Salaries ---\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }
}

float calculateAverage(float arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}

float findHighest(float arr[], int n) {
    float highest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}

float findLowest(float arr[], int n) {
    float lowest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    return lowest;
}

void searchSalary(float salaries[], int n) {
    float target;
    int found = 0;
    printf("\nEnter salary to search: ");
    scanf("%f", &target);

    for (int i = 0; i < n; i++) {
        if (salaries[i] == target) {
            printf("Salary %.2f found at position %d (Employee %d)\n",
                   target, i, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Salary %.2f not found.\n", target);
    }
}

/* ============================================================
   PART B: DEPARTMENT BUDGETS
   ============================================================ */
void captureBudgets(float budgets[], int n) {
    printf("\n--- Capture %d Department Budgets ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }
}

void displayBudgets(float budgets[], int n) {
    printf("\n--- Department Budgets ---\n");
    for (int i = 0; i < n; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }
}

float calculateTotal(float arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

void sortBudgetsAscending(float budgets[], int n) {
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

/* ============================================================
   PART C: VEHICLE REGISTRATION NUMBERS
   ============================================================ */
void captureRegistrations(char regs[][REG_LENGTH], int n) {
    printf("\n--- Capture %d Vehicle Registrations ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", regs[i]);
    }
}

void displayRegistrations(char regs[][REG_LENGTH], int n) {
    printf("\n--- Vehicle Registrations ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, regs[i]);
    }
}

void searchRegistration(char regs[][REG_LENGTH], int n) {
    char target[REG_LENGTH];
    int found = 0;
    printf("\nEnter registration number to search: ");
    scanf("%19s", target);

    for (int i = 0; i < n; i++) {
        if (strcmp(regs[i], target) == 0) {
            printf("Registration %s found at position %d.\n", target, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Registration %s not found.\n", target);
    }
}

/* ============================================================
   MAIN FUNCTION
   ============================================================ */
int main() {
    float salaries[MAX_SALARIES];
    float budgets[MAX_BUDGETS];
    char registrations[MAX_REGISTRATIONS][REG_LENGTH];

    int choice;

    do {
        printf("\n========================================\n");
        printf("  MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Capture and process employee salaries\n");
        printf("2. Capture and process department budgets\n");
        printf("3. Capture and process vehicle registrations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            captureSalaries(salaries, MAX_SALARIES);
            displaySalaries(salaries, MAX_SALARIES);
            printf("\nAverage salary: %.2f\n", calculateAverage(salaries, MAX_SALARIES));
            printf("Highest salary: %.2f\n", findHighest(salaries, MAX_SALARIES));
            printf("Lowest salary: %.2f\n", findLowest(salaries, MAX_SALARIES));
            searchSalary(salaries, MAX_SALARIES);
            break;

        case 2:
            captureBudgets(budgets, MAX_BUDGETS);
            displayBudgets(budgets, MAX_BUDGETS);
            printf("\nTotal budget: %.2f\n", calculateTotal(budgets, MAX_BUDGETS));
            printf("Average budget: %.2f\n", calculateAverage(budgets, MAX_BUDGETS));

            sortBudgetsAscending(budgets, MAX_BUDGETS);
            printf("\n--- Budgets sorted lowest to highest ---\n");
            displayBudgets(budgets, MAX_BUDGETS);
            break;

        case 3:
            captureRegistrations(registrations, MAX_REGISTRATIONS);
            displayRegistrations(registrations, MAX_REGISTRATIONS);
            searchRegistration(registrations, MAX_REGISTRATIONS);
            break;

        case 4:
            printf("Exiting program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please enter 1-4.\n");
        }

    } while (choice != 4);

    return 0;
}