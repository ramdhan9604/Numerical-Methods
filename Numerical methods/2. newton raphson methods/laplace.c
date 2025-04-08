#include <stdio.h>
#include <math.h>

#define N 5
#define MAX_ITER 3
#define TOL 1e-5
int i,j;

int main() {
    double grid[N][N];
    double new_grid[N][N];
    double diff;
    int iter = 0;

    // Initialize the boundary conditions
    for (i = 0; i < N; i++) {
        grid[i][0] = (i*i)/2;
        grid[4][i] = 8+2*i;
        grid[0][i] = 0.0;
        grid[i][4] = i*i;
    }

    while (iter < MAX_ITER) {
        diff = 0.0;

        // Update interior points using the five-point stencil
        for (i = 1; i < N - 1; i++) {
            for (j = 1; j < N - 1; j++) {
                new_grid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]);
                diff += fabs(new_grid[i][j] - grid[i][j]);
            }
        }

        // Copy the new grid back to the original grid
        for (i = 1; i < N - 1; i++) {
            for (j = 1; j < N - 1; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }

        if (diff < TOL) {
            printf("Converged after %d iterations.\n", iter);
            break;
        }

        iter++;
    }

    // Print the final grid
    for (i = 1; i < 4; i++) {
        for (j = 1; j < 4; j++) {
            printf("%0.2f ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}

