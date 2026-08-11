#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(0, 100000, "N");
    inf.readSpace();
    int t = inf.readInt(1, 1000000000, "T");
    inf.readSpace();
    int q = inf.readInt(0, 100000, "Q");
    inf.readEoln();

    int last_c = -1;
    for (int i = 0; i < n; ++i) {
        int c = inf.readInt(0, t - 1, "C_i");
        inf.readSpace();
        
        ensuref(c > last_c, "C must be strictly increasing: %d > %d", c, last_c);
        last_c = c;

        string s = inf.readToken("[/\\-\\\\]", "M_i");
        inf.readEoln();
    }

    for (int i = 0; i < q; ++i) {
        inf.readInt(0, t, "L_i");
        inf.readSpace();
        inf.readInt(0, t, "R_i");
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}
