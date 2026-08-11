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

const int MAXA = (int)1e6 + 5;
bitset<MAXA> isprime;
vector<int> primes;

void init() {
    isprime.set();
    isprime[0] = 0; isprime[1] = 0;

    for (int i = 2; i * i < MAXA; ++i) {
        if (!isprime[i]) continue;
        for (int j = i * i; j < MAXA; j += i)
            isprime[j] = 0;
    }
    
    for (int i = 3; i < MAXA; ++i)  
        if (isprime[i]) primes.push_back(i);
}

bool is_square(ll x) {
    ll r = sqrtl((ld)x);

    while ((r + 1) <= x / (r + 1)) ++r;
    while (r > x / r) --r;

    return r * r == x;
}

void solve() {
    ll n; cin >> n; 

    if (n & 1) {
        cout << 0 << '\n';
        return;
    }

    while (n % 2 == 0) n /= 2;

    ll res = 1;

    for (int p : primes) {
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            ++cnt;
        }

        res *= (ll)(cnt / 2 + 1);
    }

    if (n > 1) {
        if (is_square(n)) res *= 2;
    }

    cout << res << '\n';
}

signed main() {
    #ifdef NCTHANH
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}