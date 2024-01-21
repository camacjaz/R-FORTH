#include <stdio.h>

int main() {
    double num1, num2; // Declare variables to store input

    printf("Enter first number: "); // Prompt user for input
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Perform operations
    double sum = num1 + num2;
    double difference = num1 - num2;
    double product = num1 * num2;

    // Check if the second number is not zero before performing division
    if (num2 != 0) {
        double quotient = num1 / num2;

        // Display results
        printf("Sum: %.2lf\n", sum);
        printf("Difference: %.2lf\n", difference);
        printf("Product: %.2lf\n", product);
        printf("Quotient: %.2lf\n", quotient);
    } else {
        printf("Cannot divide by zero.\n");
    }

    return 0;
}
