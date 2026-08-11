#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[501][501][201];
long long a[501][501];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, n, k;
    cin >> m >> n >> k;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            for (int r = 0; r < k; r++)
                dp[i][j][r] = -1;

    dp[1][1][a[1][1] % k] = a[1][1];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int r = 0; r < k; r++) {
                if (dp[i][j][r] == -1) continue;
                
                if (i + 1 <= m) {
                    int next_rem = (r + a[i + 1][j]) % k;
                    dp[i + 1][j][next_rem] = max(dp[i + 1][j][next_rem], dp[i][j][r] + a[i + 1][j]);
                }
                
                if (j + 1 <= n) {
                    int next_rem = (r + a[i][j + 1]) % k;
                    dp[i][j + 1][next_rem] = max(dp[i][j + 1][next_rem], dp[i][j][r] + a[i][j + 1]);
                }
            }
        }
    }

    cout << dp[m][n][0] << "\n";
    
    return 0;
}
