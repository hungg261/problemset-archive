#include <iostream>

using namespace std;

int main() {
    long long a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    long long min_sum = a + c;
    long long max_sum = b + d;

    long long rem = min_sum % k;
    long long s = min_sum;
    if (rem != 0) {
        s += (k - rem);
    }

    if (s <= max_sum) {
        long long x = a;
        long long y = s - x;
        if (y > d) {
            y = d;
            x = s - y;
        }
        cout << x << " " << y << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
