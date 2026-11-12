#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>

using namespace std;

bool inDomain(double x) {
    return isfinite(x) && x > 3.0 && x <= 5.0;
}

double f(double x) {
    const double pi = numbers::pi_v<double>;
    const double e = numbers::e_v<double>;
    return cos(12.0 / 61.0)
        + (13.0 * pi / (51.0 * e)) * 12.0 / ((x - 8.0) * (x - 6.0))
        + 5.0 * acos(x - 4.0)
        + log(x - 3.0) / log(14.0);
}

int main() {
    cout << "Kroshchuk Eva Mykolaivna, K-15\n";
    cout << "Laboratory work 1, variant 36\n";
    cout << "Calculation of a mathematical function\n";
    cout << "Enter x (3 < x <= 5): ";

    double x;
    if (!(cin >> x)) {
        cout << "\nwrong input\n";
    } else {
        cout << "\n***** do calculations ... ";
        const bool defined = inDomain(x);
        double result = 0.0;
        if (defined) {
            result = f(x);
        }
        cout << "done\n";
        cout << fixed << setprecision(5) << "for x = " << x << '\n';
        if (defined) {
            cout << fixed << setprecision(9) << "result = " << result << '\n';
        } else {
            cout << "result = undefined\n";
        }
    }
}
