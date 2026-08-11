#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 500);
    inf.readSpace();
    int m = inf.readInt(1, 500);
    inf.readSpace();
    int k = inf.readInt(1, 26);
    inf.readEoln();

    int s = 0, t = 0;
    for (int i = 0; i < n; i++) {
        string row = inf.readToken(format("[.#sStTwW]{%d}", m));
        inf.readEoln();
        for (char c : row) {
            if (c == 's' || c == 'S') s++;
            if (c == 't' || c == 'T') t++;
        }
    }

    ensuref(s == 1, "Must have 1 S");
    ensuref(t == 1, "Must have 1 T");

    for (int i = 0; i < k; i++) {
        inf.readInt(1, 26);
        if (i < k - 1) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();

    return 0;
}
