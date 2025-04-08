#include <stdio.h>
#include <math.h>

#define NX 5  // Number of grid points in the x direction
#define NY 5  // Number of grid points in the y direction
#define MAX_ITER 3  // Maximum number of iterations
#define TOL 1e-5  // Tolerance for convergence
int i,j;
// Function to initialize the grid with boundary conditions
void initializeGrid(double grid[NX][NY]) {
    // Set boundary conditions (e.g., u=0 on all boundaries)
    for (i = 0; i < NX; i++) {
        grid[i][0] = 0.0;
        grid[i][NY - 1] = 0.0;
    }
    for (j = 0; j < NY; j++) {
        grid[0][j] = 0.0;
        grid[NX - 1][j] = 0.0;
    }
}


int main() {
    double grid[NX][NY];  // Grid for storing the solution
    double newGrid[NX][NY];  // Temporary grid for the updated solution
    int iter = 0;
    double maxDiff;

    // Initialize the grid
    initializeGrid(grid);
    initializeGrid(newGrid);

    // Main iterative loop
    while (iter < MAX_ITER) {
        maxDiff = 0.0;

        for (i = 1; i < NX - 1; i++) {
            for (j = 1; j < NY - 1; j++) {
                // Update the solution using the five-point stencil
                newGrid[i][j] = 0.25 * (grid[i + 1][j] + grid[i - 1][j] + grid[i][j + 1] + grid[i][j - 1]);

                // Calculate the maximum difference for convergence check
                double diff = fabs(newGrid[i][j] - grid[i][j]);
                if (diff > maxDiff) {
                    maxDiff = diff;
                }
            }
        }

        // Swap grids for the next iteration
        for (i = 1; i < NX - 1; i++) {
            for (j = 1; j < NY - 1; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }

        iter++;

        // Check for convergence
        if (maxDiff < TOL) {
            break;
        }
    }

    // Print the final solution
    printf("Solution after %d iterations:\n", iter);
    for (j = NY - 1; j >= 0; j--) {
        for (i = 0; i < NX; i++) {
            printf("%0.2f ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}

