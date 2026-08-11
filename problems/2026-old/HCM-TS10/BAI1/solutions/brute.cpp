#include <iostream>

using namespace std;

int main() {
    long long a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    for (long long x = a; x <= b; ++x) {
        for (long long y = c; y <= d; ++y) {
            if ((x + y) % k == 0) {
                cout << x << " " << y << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
