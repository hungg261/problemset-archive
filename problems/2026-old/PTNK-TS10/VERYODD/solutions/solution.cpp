#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long u64;
typedef __int128_t u128;

u64 gcd_fast(u64 a, u64 b) {
    if (a == 0) return b;
    if (b == 0) return a;
    int shift = __builtin_ctzll(a | b);
    a >>= __builtin_ctzll(a);
    do {
        b >>= __builtin_ctzll(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

inline u64 mul_mod(u64 a, u64 b, u64 m) {
    return (u64)((u128)a * b % m);
}

u64 power(u64 base, u64 exp, u64 mod) {
    u64 res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = mul_mod(res, base, mod);
        base = mul_mod(base, base, mod);
        exp >>= 1;
    }
    return res;
}

bool miller_rabin(u64 n) {
    if (n < 2) return false;
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return false;

    u64 d = n - 1;
    int s = __builtin_ctzll(d);
    d >>= s;

    static const u64 bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (u64 a : bases) {
        if (n <= a) break;
        u64 x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

u64 pollard_rho(u64 n) {
    if (n % 2 == 0) return 2;
    if (miller_rabin(n)) return n;
    
    u64 x = 2, y = 2, d = 1, c = 1;
    auto f = [&](u64 x, u64 n, u64 c) {
        return (mul_mod(x, x, n) + c) % n;
    };

    while (d == 1) {
        x = f(x, n, c);
        y = f(f(y, n, c), n, c);
        d = gcd_fast(x > y ? x - y : y - x, n);
        if (d == n) {
            x = 2;
            y = 2;
            c++; 
            d = 1;
        }
    }
    return d;
}

void factorize(u64 n, vector<u64>& factors) {
    if (n == 1) return;
    if (miller_rabin(n)) {
        factors.push_back(n);
        return;
    }
    u64 divisor = pollard_rho(n);
    factorize(divisor, factors);
    factorize(n / divisor, factors);
}

void solve() {
    int q;
    if (!(cin >> q)) return;

    static const int SMALL_PRIMES[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    while (q--) {
        u64 n;
        cin >> n;

        if (n % 2 != 0) {
            cout << 0 << "\n";
            continue;
        }

        while (n % 2 == 0) {
            n /= 2;
        }

        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        vector<u64> factors;
        
        for (int p : SMALL_PRIMES) {
            if (n % p == 0) {
                while (n % p == 0) {
                    factors.push_back(p);
                    n /= p;
                }
            }
        }
        
        if (n > 1) {
            factorize(n, factors);
        }

        sort(factors.begin(), factors.end());
        u64 ans = 1;
        int count = 1;
        
        for (size_t i = 1; i < factors.size(); ++i) {
            if (factors[i] == factors[i - 1]) {
                count++;
            } else {
                ans *= (count / 2 + 1);
                count = 1;
            }
        }
        if (!factors.empty()) {
            ans *= (count / 2 + 1);
        }

        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    return 0;
}