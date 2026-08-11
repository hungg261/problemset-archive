/*
Author: Nguyen Chi Thanh - High School for the Gifted - VNU.HCM (i2528)
*/
#include <bits/stdc++.h>
using namespace std;

/* START OF TEMPALTE */

// #define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define popcount __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(x) (1ll << (x))
#define SZ(a) ((int32_t)a.size())

#define debug(a, l, r) {for (int _i = (l); _i <= (r); ++_i) cout << (a)[_i] << ' '; cout << '\n';}

template<class X, class Y>
bool minimize(X &x, const Y &y) {
    if (x > y) {
        x = y;
        return true;
    } else return false;
}

template<class X, class Y>
bool maximize(X &x, const Y &y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}

/* END OF TEMPALTE */

int convert(char c) {
    if (c == 'T') return 0;
    if (c == 'R') return 1;
    return 2;
}

char convert(int x) {
    if (x == 0) return 'T';
    if (x == 1) return 'R';
    return 'M';
}

int n, cnt[3]; string s;

void init() {
    cin >> n >> s;
    for (char c : s) cnt[convert(c)]++;
}

int cntOp(const string &a, const string &b) {
    vector<vector<int>> freq(3, vector<int>(3, 0));

    for (int i = 0; i < n; ++i)
        freq[convert(a[i])][convert(b[i])]++;

    int res = 0, rem = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 3; ++j) {
            int d = min(freq[i][j], freq[j][i]);
            res += d;
            freq[i][j] -= d; freq[j][i] -= d;
            rem += freq[i][j] + freq[j][i];
        }
    
    int ans = res + 2 * (rem / 3);
    return ans;
}

void solve() {
    vector<int> perm(3);
    iota(all(perm), 0);

    int res = (int)1e9 + 67;
    do {
        string t = "";
        for (int i = 0; i < 3; ++i)
            for (int j = 1; j <= cnt[perm[i]]; ++j)
                t += convert(perm[i]);
        minimize(res, cntOp(s, t));
    } while (next_permutation(all(perm)));

    cout << res;
}

signed main() {
    #ifdef NCTHANH
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    solve();

    return 0;
}