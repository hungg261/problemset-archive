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

    for (int w = 0; w <= 2000005; ++w) {
        if (count_robots(X, w) + count_robots(Y, w) <= n) {
            cout << w << "\n";
            return 0;
        }
    }

    return 0;
}
