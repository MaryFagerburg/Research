#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

// Differential equation: dx/dt = -3x
double f(double t, double x) {
    return -3.0 * x;
}

int main() {
    // Number of steps
    int N = 30;

    // Three step sizes
    double h_values[3] = {0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4};

    // Create CSV file
    std::ofstream file("euler_output.csv");

    if (!file) {
        std::cout << "Error opening file.\n";
        return 1;
    }

    file << std::fixed << std::setprecision(6);

    // Header row
    file << "Step_size,Step,t,Euler_x\n";

    // Loop through each step size
    for (int j = 0; j < 7; j++) {
        double h = h_values[j];

        // Reset initial conditions
        double t = 0.0;
        double x = 1.0;   // x(0)=1

        for (int i = 0; i <= N; i++) {
            // Write data row
            file << h << ","
                 << i << ","
                 << t << ","
                 << x << "\n";

            // Euler update
            x = x + h * f(t, x);
            t = t + h;
        }

        // Blank line between step-size sections
        file << "\n";
    }

    file.close();

    std::cout << "Data written to euler_output.csv\n";

    return 0;
}
