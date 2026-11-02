#include <stdio.h>
#include <string.h>
#include "utilities.h"

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard */
    }
}

int readInt(const char *prompt)
{
    int value;
    printf("%s", prompt);
    if (scanf("%d", &value) != 1) {
        clearInputBuffer();
        return 0;
    }
    clearInputBuffer();
    return value;
}

float readFloat(const char *prompt)
{
    float value;
    printf("%s", prompt);
    if (scanf("%f", &value) != 1) {
        clearInputBuffer();
        return 0.0f;
    }
    clearInputBuffer();
    return value;
}

void readString(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    clearInputBuffer();
}