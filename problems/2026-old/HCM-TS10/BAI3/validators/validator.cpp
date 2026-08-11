#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

signed main(int argc, char* argv[]){
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 500000, "n");
    inf.readEoln();
    
    string s = inf.readToken("[TRM]{" + to_string(n) + "}", "s");
    inf.readEoln();
    
    inf.readEof();

    return 0;
}
