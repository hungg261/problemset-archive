#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
long long a[501][501];
long long memo[501][501][201];
bool visited[501][501][201];

long long solve(int r, int c, int rem) {
    if (r > m || c > n) return -2;
    if (r == m && c == n) {
        if ((rem + a[r][c]) % k == 0) return a[r][c];
        return -2;
    }
    if (visited[r][c][rem]) return memo[r][c][rem];

    int next_rem = (rem + a[r][c]) % k;
    long long down = solve(r + 1, c, next_rem);
    long long right = solve(r, c + 1, next_rem);

    long long res = max(down, right);
    if (res != -2) res += a[r][c];

    visited[r][c][rem] = true;
    return memo[r][c][rem] = res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    long long ans = solve(1, 1, 0);
    if (ans < 0) cout << -1;
    else cout << ans << "\n";
    
    return 0;
}
