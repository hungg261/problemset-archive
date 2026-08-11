#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Order {
    int t, m;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, Q;
    long long T, a, b;
    cin >> n >> T >> Q >> a >> b;

    vector<Order> orders;
    orders.push_back({0, 1});
    for (int i = 0; i < n; ++i) {
        int t, m;
        cin >> t >> m;
        if (t == 0) orders[0].m = m;
        else orders.push_back({t, m});
    }
    orders.push_back({(int)T, 0});

    while (Q--) {
        int L, R;
        cin >> L >> R;
        long long total = 0;
        for (int i = 0; i < (int)orders.size() - 1; ++i) {
            int start = max(L, orders[i].t);
            int end = min(R, orders[i + 1].t);
            if (start < end) {
                long long speed = (orders[i].m == 1) ? a : b;
                total += (long long)(end - start) * speed;
            }
        }
        cout << total << "\n";
    }

    return 0;
}
