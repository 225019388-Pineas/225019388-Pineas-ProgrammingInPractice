#include <stdio.h>

/* Function declarations */
void displayWelcome();
void displayMenu();

float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);

int searchEmployee(int employeeID, int ids[], int size);

int main()
{
    int choice;

    int employeeIDs[] = {101, 102, 103, 104, 105};
    int employeeID;

    float amount;
    float vat;

    float basic;
    float housing;
    float transport;
    float salary;

    float revenue;
    float expenses;
    float budget;

    displayWelcome();

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter amount: ");
                scanf("%f", &amount);

                vat = calculateVAT(amount);

                printf("VAT: %.2f\n", vat);
                break;

            case 2:
                printf("\nEnter basic salary: ");
                scanf("%f", &basic);

                printf("Enter housing allowance: ");
                scanf("%f", &housing);

                printf("Enter transport allowance: ");
                scanf("%f", &transport);

                salary = calculateSalary(basic, housing, transport);

                printf("Gross Salary: %.2f\n", salary);
                break;

            case 3:
                printf("\nEnter revenue: ");
                scanf("%f", &revenue);

                printf("Enter expenses: ");
                scanf("%f", &expenses);

                budget = calculateBudget(revenue, expenses);

                printf("Budget balance: %.2f\n", budget);

                if (budget > 0)
                {
                    printf("SURPLUS\n");
                }
                else if (budget < 0)
                {
                    printf("DEFICIT\n");
                }
                else
                {
                    printf("BALANCED\n");
                }

                break;

            case 4:
                printf("\nEnter employee ID: ");
                scanf("%d", &employeeID);

                int position;

                position = searchEmployee(
                    employeeID,
                    employeeIDs,
                    5
                );

                if (position != -1)
                {
                    printf("Employee found at position %d.\n",
                           position);
                }
                else
                {
                    printf("Employee not found.\n");
                }

                break;

            case 5:
                printf("\nSupplier Management\n");
                printf("Supplier module from Week 7.\n");
                break;

            case 6:
                printf("\nGoodbye.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}

/* Displays welcome message */
void displayWelcome()
{
    printf("==========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("==========================================\n");
}

/* Displays menu */
void displayMenu()
{
    printf("\n==========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("==========================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

/* Calculates VAT */
float calculateVAT(float amount)
{
    return amount * 0.15;
}

/* Calculates gross salary */
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

/* Calculates budget balance */
float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

/* Searches for an employee */
int searchEmployee(int employeeID, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == employeeID)
        {
            return i;
        }
    }

    return -1;
}