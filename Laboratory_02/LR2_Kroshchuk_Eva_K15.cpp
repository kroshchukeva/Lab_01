#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

int main() {
    cout << "Kroshchuk Eva Mykolaivna, K-15\n";
    cout << "Laboratory work 2, variant 36\n";
    cout << "Calculation of a power series on [-1; 1]\n";

    double x, eps;
    cout << "Enter x from [-1; 1]: ";
    if (!(cin >> x)) {
        cout << "***** error\nInvalid input for x.\n";
        return 1;
    }
    if (!isfinite(x) || x < -1.0 || x > 1.0) {
        cout << "***** error\nx must be in [-1; 1].\n";
        return 1;
    }

    cout << "Enter positive eps: ";
    if (!(cin >> eps)) {
        cout << "***** error\nInvalid input for eps.\n";
        return 1;
    }
    if (!isfinite(eps) || eps <= 0.0) {
        cout << "***** error\neps must be positive and finite.\n";
        return 1;
    }

    cout << "***** do calculations ...\n";

    double term = x;
    double sum = 0.0;
    unsigned int n = 0;
    while (fabs(term) >= eps) {
        double nextSum = sum + term;
        if (nextSum == sum) {
            cout << "***** error\nRequested precision cannot be achieved.\n";
            return 1;
        }
        sum = nextSum;
        double k = static_cast<double>(n);
        term *= x * x * x * x * (4.0 * k + 1.0) /
                ((2.0 * k + 1.0) * (2.0 * k + 2.0) * (4.0 * k + 5.0));
        ++n;
    }

    cout << "done\n";
    cout << scientific << setprecision(7) << "for x = " << x << '\n';
    cout << scientific << setprecision(9) << "for eps = " << eps << '\n';
    cout << fixed << setprecision(8) << "result = " << sum << '\n';
    return 0;
}
