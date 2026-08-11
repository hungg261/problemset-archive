#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

signed main(int argc, char* argv[]){
    registerValidation(argc, argv);
    
    const int MAXVAL = 1e9;
    int n = inf.readInt(1, 300'000, "n");
    inf.readEoln();
    for(int i = 1; i <= n; ++i){
        inf.readInt(-MAXVAL, MAXVAL, format("a[%d]", i));
        if(i < n) inf.readSpace();
    }

    inf.readEoln();
    inf.readEof();

    return 0;
}