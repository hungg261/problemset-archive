#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long d;
    cin >> n >> d;
    if (n <= 1) {
        cout << 0;
        return 0;
    }
    vector<long long> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (abs(h[i+1] - h[i]) > d) ans++;
    }
    cout << ans;
    return 0;
}
