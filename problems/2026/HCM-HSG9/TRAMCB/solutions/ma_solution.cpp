#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while(b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    ll k = gcd(n, m);

    cout << k << "\n";
    cout << n / k << " " << m / k << "\n";

    return 0;
}