#include <iostream>
using namespace std;

int main() {
    int d1, d2, maxD;

    cout << "Degree of 1st poly: ";
    cin >> d1;
    int a[d1 + 1];
    cout << "Coeffs (high to low): ";
    for (int i = 0; i <= d1; i++) cin >> a[i];

    cout << "Degree of 2nd poly: ";
    cin >> d2;
    int b[d2 + 1];
    cout << "Coeffs (high to low): ";
    for (int i = 0; i <= d2; i++) cin >> b[i];

    maxD = (d1 > d2) ? d1 : d2;
    int res[maxD + 1];
    for (int i = 0; i <= maxD; i++) res[i] = 0;

    for (int i = 0; i <= d1; i++) res[maxD - d1 + i] = a[i];
    for (int i = 0; i <= d2; i++) res[maxD - d2 + i] -= b[i];

    cout << "Result: ";
    bool first = true;
    for (int i = 0; i <= maxD; i++) {
        if (res[i] != 0) {
            if (!first) cout << " + ";
            cout << res[i];
            if (maxD - i > 0) cout << "x^" << maxD - i;
            first = false;
        }
    }
    if (first) cout << "0";
    cout << endl;

    return 0;
}