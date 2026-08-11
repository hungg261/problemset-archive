#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define int long long

int32_t main(int32_t argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const string sub = opt<string>(2);
    const string param = opt<string>(3, "max");

    int N = 1e5, T = 1e9, Q = 1e5;
    vector<pair<int, char>> changes;
    vector<char> types = {'/', '-', '\\'};

    if (sub == "sub1") {
        N = 0;
        T = (param == "small") ? 10 : 1e9;
        Q = (param == "small") ? 5 : 1e5;
    } 
    else if (sub == "sub2") {
        N = 1;
        T = (param == "small") ? 100 : 1e9;
        Q = 1e5;
        int c = rnd.next(1LL, T - 1);
        char s = (rnd.next(0, 1) == 0) ? '/' : '\\';
        changes.push_back({c, s});
    } 
    else if (sub == "sub3") {
        N = 1000; T = 1000; Q = 1000;
    } 
    else if (sub == "sub4") {
        N = 1e5; T = 1e5; Q = 1e5;
    } 
    else {
        N = 1e5; T = 1e9; Q = 1e5;
    }

    if (sub != "sub1" && sub != "sub2") {
        set<int> used_c;
        int target_N = rnd.next(N / 2, N);
        while (used_c.size() < (size_t)target_N) {
            used_c.insert(rnd.next(1LL, T - 1));
        }
        for (int c : used_c) {
            changes.push_back({c, types[rnd.next(0, 2)]});
        }
    }

    cout << changes.size() << " " << T << " " << Q << endl;
    for (auto p : changes) {
        cout << p.first << " " << p.second << endl;
    }

    for (int i = 0; i < Q; ++i) {
        int l = rnd.next(0LL, N);
        int r = rnd.next(l, N); // possibly <= T
        if (l > r) swap(l, r); // possible <= T
        if (param == "edge" && rnd.next(1, 10) == 1) r = l; 
        if (rnd.next(1, 5) == 1) l = 0; 
        cout << l << " " << r << endl;
    }

    return 0;
}
