#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();
    sort(s.begin(), s.end());

    int min_pieces = n;

    do {
        for (int mask = 0; mask < (1 << (n - 1)); mask++) {
            vector<string> pieces;
            string current = "";
            current += s[0];

            for (int i = 0; i < n - 1; i++) {
                if ((mask >> i) & 1) {
                    pieces.push_back(current);
                    current = "";
                }
                current += s[i + 1];
            }
            pieces.push_back(current);

            bool all_ok = true;
            for (string p : pieces) {
                if (!isPalindrome(p)) {
                    all_ok = false;
                    break;
                }
            }

            if (all_ok) {
                min_pieces = min(min_pieces, (int)pieces.size());
            }
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << min_pieces << "\n";

    return 0;
}
