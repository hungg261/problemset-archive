#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

signed main(int argc, char* argv[]){
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 100'000, "n");
    inf.readSpace();
    int T = inf.readInt(1, 1'000'000'000, "T");
    inf.readSpace();
    int Q = inf.readInt(1, 100'000, "Q");
    inf.readSpace();
    int a = inf.readInt(1, 1'000'000, "a");
    inf.readSpace();
    int b = inf.readInt(1, 1'000'000, "a");
    inf.readEoln();

    vector<int> t;
    for(int i = 1; i <= n; ++i){
        int t_i = inf.readInt(0, T, format("t_%d", i));
        t.push_back(t_i);

        inf.readSpace();
        inf.readInt(1, 2, format("m_%d", i));
        inf.readEoln();
    }

    ensuref(is_sorted(begin(t), end(t), less<int>()), "Array t is not sorted.");

    while(Q--){
        int L = inf.readInt(0, T, "L");
        inf.readSpace();
        int R = inf.readInt(L, T, "R");
        inf.readEoln();
    }

    inf.readEof();
    
    return 0;
}