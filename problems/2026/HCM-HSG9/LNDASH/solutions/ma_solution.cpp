#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

typedef long double ld;

struct Segment {
    long long t;
    ld v, p;
};

ld get_dist(char c) {
    if (c == '-') return 1.0L;
    return sqrtl(2.0L);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    long long N, T, Q;
    cin >> N >> T >> Q;

    map<long long, char> m;
    m[0] = '-'; 
    for (int i = 0; i < N; ++i) {
        long long c; char s;
        cin >> c >> s;
        m[c] = s;
    }

    vector<Segment> segs;
    ld current_p = 0;
    long long last_t = -1;
    ld last_v = 0;

    for (auto const& item : m) {
        if (last_t != -1) {
            current_p += last_v * (ld)(item.first - last_t);
        }
        segs.push_back({item.first, get_dist(item.second), current_p});
        last_t = item.first;
        last_v = get_dist(item.second);
    }

    auto get_S = [&](long long X) {
        if (segs.empty() || X <= segs[0].t) return 0.0L;
        
        int l = 0, r = (int)segs.size() - 1, idx = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (segs[mid].t < X) {
                idx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return segs[idx].p + segs[idx].v * (ld)(X - segs[idx].t);
    };

    cout << fixed << setprecision(6);
    while (Q--) {
        long long L, R;
        cin >> L >> R;
        if (L >= R) {
            cout << "0.000000\n";
        } else {
            ld res = get_S(R) - get_S(L);
            cout << res << "\n";
        }
    }

    return 0;
}
