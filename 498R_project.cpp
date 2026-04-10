#include <iostream>

double f(double t, double y) {
    return -y;
}

int main() {
    double t = 0.0;
    double y = 1.0;
    double h = 0.1;
    int N = 20;

    for (int i = 0; i < N; i++) {
        y = y + h * f(t, y);
        t = t + h;

        std::cout << "t = " << t << " y = " << y << std::endl;
    }

    return 0;
}
