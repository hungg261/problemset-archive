#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    ll maxTram = 1;
    for(ll i = 1; i <= min(n, m); i++) {
        if(n % i == 0 && m % i == 0) maxTram = i;
    }

    cout << maxTram << "\n";
    cout << n / maxTram << " " << m / maxTram << "\n";

    return 0;
}