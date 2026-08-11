#include <iostream>
#include <string>

using namespace std;

bool check_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool check_pair(int x) {
    if (!check_prime(x)) return false;
    string s = to_string(x);
    for (int i = 1; i < s.length(); i++) {
        int n1 = stoi(s.substr(0, i));
        int n2 = stoi(s.substr(i));
        if (check_prime(n1) && check_prime(n2)) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r, cnt = 0;
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            if (check_pair(i)) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
