#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

signed main(int argc, char* argv[]){
    registerValidation(argc, argv);
    
    int m = inf.readInt(1, 500, "m");
    inf.readSpace();
    int n = inf.readInt(1, 500, "n");
    inf.readSpace();
    int k = inf.readInt(1, 200, "k");
    inf.readEoln();

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            inf.readInt(1, 1'000'000, format("a[%d][%d]", i, j));
            if(j < n) inf.readSpace();
        }
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}