#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50

void captureSalaries(float salaries[], int n);
void displaySalaries(float salaries[], int n);
float calculateSalary(float basic, float housing, float transport);
float calculateAverage(float arr[], int n);
float findHighest(float arr[], int n);
float findLowest(float arr[], int n);
int searchEmployee(int employeeID, int ids[], int size);
void searchSalary(float salaries[], int n);

#endif