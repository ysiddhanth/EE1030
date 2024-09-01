#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-9  // A small threshold to treat values as zero

// Function to swap two rows of the matrix
void swapRows(float **M, int row1, int row2, int n) {
    for (int i = 0; i < n; i++) {
        float temp = M[row1][i];
        M[row1][i] = M[row2][i];
        M[row2][i] = temp;
    }
}

// Function to calculate the rank of a matrix
int calculateRank(float **M, int m, int n) {
    int rank = 0;

    // Process the matrix row by row
    for (int row = 0; row < m; row++) {
        // Find the first non-zero element in the current row
        int non_zero_column = -1;
        for (int col = 0; col < n; col++) {
            if (fabs(M[row][col]) > EPSILON) {
                non_zero_column = col;
                break;
            }
        }

        // If the row is entirely zero, skip it
        if (non_zero_column == -1) {
            continue;
        }

        // Increment rank since this row contributes to the rank
        rank++;

        // Normalize the row by making the leading coefficient 1
        float leading_coefficient = M[row][non_zero_column];
        for (int col = non_zero_column; col < n; col++) {
            M[row][col] /= leading_coefficient;
        }

        // Eliminate the leading coefficient from the rows below
        for (int i = row + 1; i < m; i++) {
            float factor = M[i][non_zero_column];
            for (int col = non_zero_column; col < n; col++) {
                M[i][col] -= factor * M[row][col];
            }
        }
    }

    // Now eliminate any remaining non-zero entries above the leading 1s
    for (int row = m - 1; row > 0; row--) {
        int non_zero_column = -1;
        for (int col = 0; col < n; col++) {
            if (fabs(M[row][col]) > EPSILON) {
                non_zero_column = col;
                break;
            }
        }

        if (non_zero_column != -1) {
            for (int i = 0; i < row; i++) {
                float factor = M[i][non_zero_column];
                for (int col = non_zero_column; col < n; col++) {
                    M[i][col] -= factor * M[row][col];
                }
            }
        }
    }

    return rank;
}

int triarea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
}
