#include <stdio.h>

int main() {
    int number;

    printf("Enter a number: ");

    // Use scanf to read input
    if (scanf("%d", &number) == 1) {
        // Input is numeric
        printf("You entered: %d\n", number);
    } else {
        // Input is not numeric
        printf("Invalid input. Please enter a numeric value.\n");

        // Clear the input buffer to avoid further issues
        while(getchar() != '\n');
    }

    return 0;
}

