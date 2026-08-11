#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> X, Y;

int count_robots(const vector<int>& V, int w) {
    if (V.empty()) return 0;
    int cnt = 1;
    int last = V[0];
    for (size_t i = 1; i < V.size(); ++i) {
        if (V[i] > last + w) {
            cnt++;
            last = V[i];
        }
    }
    return cnt;
}

bool check(int w) {
    long long total = (long long)count_robots(X, w) + count_robots(Y, w);
    return total <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    X.resize(m);
    Y.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> X[i] >> Y[i];
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    int low = 0, high = 1e9, ans = 1e9;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
