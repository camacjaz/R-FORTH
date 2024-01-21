#include <stdio.h>

int main() {

    int numbers[] = {10, 5, 7, 2, 8}; // Declare an array of integers

    
    int num_elements = sizeof(numbers) / sizeof(numbers[0]); // Calculate the number of elements in the array

    // Initialize variables for sum and average
    int sum = 0;
    double average;

    // Calculate the sum of elements
    for (int i = 0; i < num_elements; i++) {
        sum += numbers[i];
    }

    // Calculate the average (avoid division by zero)
    if (num_elements != 0) {
        average = (double)sum / num_elements;

        // Display results
        printf("Sum: %d\n", sum);
        printf("Average: %.2lf\n", average);
    } else {
        printf("Array is empty. Cannot calculate average.\n");
    }

    return 0;
}
