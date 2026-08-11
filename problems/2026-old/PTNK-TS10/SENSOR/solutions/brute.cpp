#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n + 1);
    vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    long long ans = 0;

    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            long long sum = pref[r] - pref[l - 1];
            long long len = r - l + 1;
            long long target = l + r;

            if (sum == target * len) {
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
