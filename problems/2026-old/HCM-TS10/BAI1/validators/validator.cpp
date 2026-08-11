#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

signed main(int argc, char* argv[]){
    registerValidation(argc, argv);

    long long a = inf.readLong(1LL, 1000000000000LL, "a"); // 1e12
    inf.readSpace();
    long long b = inf.readLong(1LL, 1000000000000LL, "b");
    inf.readSpace();
    long long c = inf.readLong(1LL, 1000000000000LL, "c");
    inf.readSpace();
    long long d = inf.readLong(1LL, 1000000000000LL, "d");
    inf.readSpace();
    long long k = inf.readLong(1LL, 1000000000000LL, "k");
    inf.readEoln();
    inf.readEof();

    ensuref(a <= b, "uh oh a <= b");
    ensuref(c <= d, "uh oh c <= d");

    return 0;
}
