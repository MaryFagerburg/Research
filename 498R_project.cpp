#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

// Differential equation: dx/dt = -3x
double f(double t, double x) {
    return -3.0 * x;
}

int main() {
    // Initial conditions
    double t = 0.0;
    double x = 1.0;   // x(0) = 1

    // Step size and number of steps
    double h = 0.1;
    int N = 100;

    std::ofstream file("euler_output.csv");

    if (!file) {
        std::cout << "Error opening file.\n";
        return 1;
    }

    file << std::fixed << std::setprecision(6);
    file << "Step,t,Euler_x,Exact_x,Error\n";

   // for (int i = 0; i <= N; i++) {
        // Exact solution: x(t) = e^(-3t)
     //   double exact = exp(-3.0 * t);
       // double error = fabs(x - exact);

       // file << i << ","
         //    << t << ","
           //  << x << ","
           //  << exact << ","
           //  << error << "\n";

        // Euler update
       // x = x + h * f(t, x);
       // t = t + h;
    }

	

    file.close();

    std::cout << "Data written to euler_output.csv\n";

    return 0;
}
