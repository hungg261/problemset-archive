#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

signed main(int argc, char* argv[]){
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 100'000, "n");
    inf.readSpace();
    int D = inf.readInt(0, 1'000'000'000, "D");
    inf.readEoln();

    for(int i = 1; i <= n; ++i){
        int h_i = inf.readInt(1, 1'000'000'000, format("h[%d]", i));
        if(i < n) inf.readSpace();
    }

    inf.readEoln();
    inf.readEof();

    return 0;
}