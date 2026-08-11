#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define int long long

signed main(int32_t argc, char* argv[]){
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int k = inf.readInt(1, 100, "k");
    inf.readEoln();

    for(int i = 1; i <= n; ++i){
        int a_i = inf.readInt(1, 1'000'000'000, format("a_%d", i));
        inf.readSpace();
    }

    inf.readEoln();
    inf.readEof();

    return 0;
}