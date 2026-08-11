#include <iostream>
#include <algorithm>

using namespace std;

int m, n, k;
long long a[505][505];
long long max_energy = -1;

void backtrack(int r, int c, long long current_sum) {
    long long total = current_sum + a[r][c];

    if (r == m && c == n) {
        if (total % k == 0) {
            max_energy = max(max_energy, total);
        }
        return;
    }

    if (r + 1 <= m) {
        backtrack(r + 1, c, total);
    }

    if (c + 1 <= n) {
        backtrack(r, c + 1, total);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    backtrack(1, 1, 0);

    cout << max_energy << endl;

    return 0;
}
