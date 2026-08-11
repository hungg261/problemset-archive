#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[3] = {0, 0, 0};
    for (char c : s) {
        if (c == 'T') cnt[0]++;
        else if (c == 'R') cnt[1]++;
        else cnt[2]++;
    }
    vector<int> p = {0, 1, 2};
    int ans = 2e9;
    do {
        int c[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        int start[3];
        start[p[0]] = 0;
        start[p[1]] = cnt[p[0]];
        start[p[2]] = cnt[p[0]] + cnt[p[1]];
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int actual;
            if (s[i] == 'T') actual = 0;
            else if (s[i] == 'R') actual = 1;
            else actual = 2;
            if (i >= start[p[2]]) cur = p[2];
            else if (i >= start[p[1]]) cur = p[1];
            else cur = p[0];
            c[actual][cur]++;
        }
        int ops = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                int m = min(c[i][j], c[j][i]);
                ops += m;
                c[i][j] -= m;
                c[j][i] -= m;
            }
        }
        int rem = c[0][1] + c[0][2] + c[1][0] + c[1][2] + c[2][0] + c[2][1];
        ops += (rem / 3) * 2;
        ans = min(ans, ops);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << "\n";
    return 0;
}
