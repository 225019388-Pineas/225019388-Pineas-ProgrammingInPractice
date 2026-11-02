#include <stdio.h>
#include "employees.h"

void captureSalaries(float salaries[], int n)
{
    printf("\n--- Capture %d Employee Salaries ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }
}

void displaySalaries(float salaries[], int n)
{
    printf("\n--- Employee Salaries ---\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateAverage(float arr[], int n)
{
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}

float findHighest(float arr[], int n)
{
    float highest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}

float findLowest(float arr[], int n)
{
    float lowest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    return lowest;
}

int searchEmployee(int employeeID, int ids[], int size)
{
    for (int i = 0; i < size; i++) {
        if (ids[i] == employeeID) {
            return i;
        }
    }
    return -1;
}

void searchSalary(float salaries[], int n)
{
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