#include <stdio.h>
#include <omp.h>
#include <float.h>
#include <math.h>

// Funkcija pagal užduotį
double f(double x, double y) {
    return 100 * pow(y - x * x, 2) + pow(1 - x, 2);
}

int main() {
    int id = 2314000;

    double dx = 0.0000001;
    double dy = 0.0000003;

    int mod_x = id % 39;
    int mod_y_min = id % 35;
    int mod_y_max = id % 65;

    double x_min = -(mod_x + 1) / 39.0;
    double x_max =  (mod_x + 1) / 39.0;

    double y_min = -(mod_y_min + 1) / 35.0;
    double y_max =  (mod_y_max + 1) / 35.0;

    double max_val = -DBL_MAX;

    long total_i = (long)ceil((x_max - x_min) / dx);
    long total_j = (long)ceil((y_max - y_min) / dy);

    #pragma omp parallel for collapse(2) reduction(max:max_val)
    for (long i = 0; i <= total_i; i++) {
        for (long j = 0; j <= total_j; j++) {
            double x = x_min + i * dx;
            double y = y_min + j * dy;
            double val = f(x, y);

            if (val > max_val) {
                max_val = val;
            }
        }
    }

    printf("max f(x, y) reiksme: %.10f\n", max_val);
    return 0;
}