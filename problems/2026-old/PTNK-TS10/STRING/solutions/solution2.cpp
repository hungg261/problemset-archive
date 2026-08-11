#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    map<char, int> cnt;
    for (char c : s) {
        cnt[c]++;
    }

    int odd_count = 0;
    for (auto p : cnt) {
        if (p.second % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count == 0) {
        cout << 1 << "\n";
    } else {
        cout << odd_count << "\n";
    }

    return 0;
}
