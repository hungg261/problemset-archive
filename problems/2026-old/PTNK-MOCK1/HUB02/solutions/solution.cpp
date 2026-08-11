#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 10000001;
bool is_prime[MAX];
int prefix_sum[MAX];

void sieve() {
    fill(is_prime, is_prime + MAX, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i) is_prime[j] = false;
        }
    }
}

bool is_pair_prime(int x) {
    if (!is_prime[x]) return false;
    string s = to_string(x);
    for (int i = 1; i < s.length(); i++) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i);
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        if (is_prime[n1] && is_prime[n2]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    for (int i = 1; i < MAX; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + (is_pair_prime(i) ? 1 : 0);
    }
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l - 1] << "\n";
    }
    return 0;
}
