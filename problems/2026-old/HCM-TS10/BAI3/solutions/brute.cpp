#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool check(const string &s) {
    bool has[256] = {false};
    char last = ' ';
    for (char c : s) {
        if (c != last) {
            if (has[(unsigned char)c]) return false;
            has[(unsigned char)c] = true;
            last = c;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (check(s)) {
        cout << 0 << "\n";
        return 0;
    }
    queue<string> q;
    unordered_map<string, int> dist;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        int d = dist[u];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (u[i] != u[j]) {
                    string v = u;
                    swap(v[i], v[j]);
                    if (dist.find(v) == dist.end()) {
                        dist[v] = d + 1;
                        if (check(v)) {
                            cout << d + 1 << "\n";
                            return 0;
                        }
                        q.push(v);
                    }
                }
            }
        }
    }
    return 0;
}
