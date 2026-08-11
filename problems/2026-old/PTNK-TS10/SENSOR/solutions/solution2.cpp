#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n + 1);
    vector<long long> P(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        P[i] = P[i - 1] + a[i];
    }

    map<long long, long long> freq;
    long long ans = 0;

    freq[0] = 1;

    for (int i = 1; i <= n; i++) {
        long long f_i = P[i] - 1LL * i * i - i;
        
        if (freq.count(f_i)) {
            ans += freq[f_i];
        }
        
        freq[f_i]++;
    }

    cout << ans << "\n";

    return 0;
}
