#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

signed main(int argc, char* argv[]){
    registerValidation(argc, argv);
    
    int q = inf.readInt(1, 10, "q");
    inf.readEoln();

    for(int i = 0; i < q; ++i){
        inf.readLong(1LL, 1000000000000000000LL, "n");
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}