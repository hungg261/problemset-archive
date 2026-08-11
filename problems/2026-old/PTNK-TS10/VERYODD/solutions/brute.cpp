#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool check_very_odd(ll m) {
    if (m <= 1) return false;
    ll sum_divisors = 0;
    int odd_count = 0;
    int even_count = 0;
    for (ll i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            sum_divisors += i;
            if (i % 2 == 0) even_count++;
            else odd_count++;
            if (i * i != m) {
                ll j = m / i;
                sum_divisors += j;
                if (j % 2 == 0) even_count++;
                else odd_count++;
            }
        }
    }
    return (sum_divisors % 2 != 0) && (odd_count == even_count);
}

void solve() {
    ll n;
    cin >> n;
    int result = 0;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (check_very_odd(i)) result++;
            if (i * i != n) {
                if (check_very_odd(n / i)) result++;
            }
        }
    }
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
