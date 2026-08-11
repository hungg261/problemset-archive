#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k, res = 0;
ll a[1005];

void backtrack(int i, ll sum) {
    if (i > n) {
        if (sum >= k && sum % k == 0) {
            res = max(res, sum);
        }
        return;
    }
    backtrack(i + 1, sum + a[i]);
    backtrack(i + 1, sum);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    backtrack(1, 0);
    cout << res;
    return 0;
}
