#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define int long long

vector<int> shard(int k, int S, int min_element = 1) {
    if (k * min_element > S) {
        quitf(_fail, "Error: Subtask constraints make the minimum possible sum greater than S.");
    }

    vector<int> a(k, min_element);
    int remaining_sum = S - (k * min_element);

    if (remaining_sum > 0) {
        vector<int> cuts(k - 1);
        for (int i = 0; i < k - 1; ++i) {
            cuts[i] = rnd.next(0LL, remaining_sum);
        }
        sort(cuts.begin(), cuts.end());

        int prev = 0;
        for (int i = 0; i < k - 1; ++i) {
            a[i] += (cuts[i] - prev);
            prev = cuts[i];
        }
        a[k - 1] += (remaining_sum - prev);
    }

    shuffle(a.begin(), a.end());
    return a;
}

signed main(signed argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int min_n = opt<int>("min_n", 0);
    int max_n = opt<int>("max_n", (int)1e5);
    int min_t = opt<int>("min_t", 1);
    int max_t = opt<int>("max_t", (int)1e9);
    int min_q = opt<int>("min_q", 1);
    int max_q = opt<int>("max_q", (int)1e5);
    string param = opt<string>("param", "max");
    string exclude = opt<string>("exclude", "");

    int N = rnd.next(min_n, max_n);
    int T = rnd.next(min_t, max_t);
    int Q = rnd.next(min_q, max_q);

    vector<pair<int, char>> changes;
    vector<char> types;
    for (char c : {'/', '-', '\\'}) {
        if (exclude.find(c) == string::npos) {
            types.push_back(c);
        }
    }

    if (N > 0 && !types.empty() && T > 1) {        
        vector<int> partitions = shard(N, T - 1, 1);
        int current_c = 0;
        for (int i = 0; i < N; ++i) {
            current_c += partitions[i];
            char s = types[rnd.next(0LL, (int)types.size() - 1)];
            changes.push_back({current_c, s});
        }
    }

    cout << changes.size() << " " << T << " " << Q << endl;
    for (auto p : changes) {
        cout << p.first << " " << p.second << endl;
    }

    for (int i = 0; i < Q; ++i) {
        int l = rnd.next(0LL, T);
        int r = rnd.next(l, T);
        if (param == "edge" && rnd.next(1, 10) == 1) {
            r = l;
        }
        if (rnd.next(1, 5) == 1) {
            l = 0;
        }
        cout << l << " " << r << endl;
    }

    return 0;
}
