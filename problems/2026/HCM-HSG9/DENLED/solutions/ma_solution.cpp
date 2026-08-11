#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> dp(k, -INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<ll> next_dp = dp;
        int rem_a = a[i] % k;
        for (int r = 0; r < k; r++) {
            if (dp[r] != -INF) {
                int next_r = (r + rem_a) % k;
                next_dp[next_r] = max(next_dp[next_r], dp[r] + a[i]);
            }
        }
        dp = next_dp;
    }

    if (dp[0] < k) cout << 0;
    else cout << dp[0];

    return 0;
}
