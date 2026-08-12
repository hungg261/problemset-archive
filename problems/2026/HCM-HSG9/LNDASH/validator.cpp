#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(0, (int)1e5, "N");
    inf.readSpace();
    int t = inf.readInt(1, (int)1e9, "T");
    inf.readSpace();
    int q = inf.readInt(1, (int)1e5, "Q");
    inf.readEoln();

    int last_c = 0;
    for (int i = 0; i < n; ++i) {
        int c = inf.readInt(last_c + 1, t - 1, format("c[%d]~", i + 1));
        inf.readSpace();
        char s = inf.readChar();
        ensuref(s == '/' || s == '-' || s == '\\', "Invalid character: %c", s);
        inf.readEoln();
        last_c = c;
    }

    for (int i = 0; i < q; ++i) {
        int l = inf.readInt(0, t, format("l[%d]~", i + 1));
        inf.readSpace();
        inf.readInt(l, t, format("r[%d]~", i + 1));
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}
