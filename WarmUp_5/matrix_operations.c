#include <stdio.h>

void addMatrices(int rows, int columns, int a[rows][columns], int b[rows][columns], int sum[rows][columns]);
void multiplyMatrices(int rowsA, int columnsA, int columnsB, int a[rowsA][columnsA], int b[columnsA][columnsB], int product[rowsA][columnsB]);
void printMatrix(int rows, int columns, int matrix[rows][columns]);

int main() {
    int matrix1[2][2] = {{1, 2}, {3, 4}};
    int matrix2[2][2] = {{5, 6}, {7, 8}};

    int sum[2][2];
    int product[2][2];

    addMatrices(2, 2, matrix1, matrix2, sum);
    multiplyMatrices(2, 2, 2, matrix1, matrix2, product);

    printf("Matrix Addition:\n");
    printMatrix(2, 2, sum);

    printf("Matrix Multiplication:\n");
    printMatrix(2, 2, product);

    return 0;
}

void addMatrices(int rows, int columns, int a[rows][columns], int b[rows][columns], int sum[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int rowsA, int columnsA, int columnsB, int a[rowsA][columnsA], int b[columnsA][columnsB], int product[rowsA][columnsB]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            for (int k = 0; k < columnsA; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int rows, int columns, int matrix[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
