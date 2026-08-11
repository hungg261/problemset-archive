#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int t;
    long long speed;
    long long prefix_dist;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, Q;
    long long T, a, b;
    cin >> n >> T >> Q >> a >> b;

    vector<pair<int, int>> input_orders;
    input_orders.push_back({0, 1});
    for (int i = 0; i < n; ++i) {
        int ti, mi;
        cin >> ti >> mi;
        if (ti == 0) input_orders[0].second = mi;
        else input_orders.push_back({ti, mi});
    }

    vector<Node> timeline;
    long long current_dist = 0;

    for (int i = 0; i < (int)input_orders.size(); ++i) {
        int start_t = input_orders[i].first;
        long long v = (input_orders[i].second == 1) ? a : b;
        
        if (i > 0) {
            current_dist += (long long)(start_t - input_orders[i-1].first) * ((input_orders[i-1].second == 1) ? a : b);
        }
        timeline.push_back({start_t, v, current_dist});
    }

    auto get_dist = [&](int time) {
        if (time <= 0) return 0LL;
        auto it = upper_bound(timeline.begin(), timeline.end(), time, [](int val, const Node& node) {
            return val < node.t;
        });
        --it;
        return it->prefix_dist + (long long)(time - it->t) * it->speed;
    };

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << get_dist(R) - get_dist(L) << "\n";
    }

    return 0;
}
