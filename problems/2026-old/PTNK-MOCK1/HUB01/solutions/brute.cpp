#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int d;
    cin >> n >> d;
    if (n <= 1) {
        cout << 0;
        return 0;
    }
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (abs(h[i+1] - h[i]) > d) ans++;
    }
    cout << ans;
    return 0;
}
