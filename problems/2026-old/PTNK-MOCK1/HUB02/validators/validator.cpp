#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

signed main(int argc, char* argv[]){
    registerValidation(argc, argv);
    
    int T = inf.readInt(1, 100'000, "T");
    inf.readEoln();

    while(T--){
        int L = inf.readInt(1, 10'000'000, "L");
        inf.readSpace();
        int R = inf.readInt(L, 10'000'000, "R");
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}