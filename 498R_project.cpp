#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

// dx/dt = -3x
double f(double t, double x) {
    return -3.0 * x;
}

int main() {

    // Step sizes
    double h_values[7] = {0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4};

    // Final time (same for all runs)
    double t_final = 3.0;

    std::ofstream file("euler_output.csv");

    if (!file) {
        std::cout << "Error opening file.\n";
        return 1;
    }

    file << std::fixed << std::setprecision(6);

    // Header
    file << "Step_size,Step,t,Euler_x\n";

    // Loop over step sizes
    for (int j = 0; j < 7; j++) {

        double h = h_values[j];

        double t = 0.0;
        double x = 1.0;

        int i = 0;

        // Run until same final time for every h
        while (t <= t_final) {

            file << h << ","
                 << i << ","
                 << t << ","
                 << x << "\n";

            x = x + h * f(t, x);
            t = t + h;
            i++;
        }
    }

    file.close();

    std::cout << "Data written to euler_output.csv\n";

    return 0;
}
