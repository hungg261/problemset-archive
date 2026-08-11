#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>(2);
    string allowed_chars = opt<string>(3, "TRM");
    
    println(n);
    
    string s = "";
    for (int i = 0; i < n; ++i) {
        s += rnd.any(allowed_chars);
    }
    println(s);

    return 0;
}
