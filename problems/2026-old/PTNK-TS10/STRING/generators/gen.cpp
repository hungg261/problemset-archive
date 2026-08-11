#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>(2);
    string _minChar = opt<string>(3), _maxChar = opt<string>(4);
    char minChar = _minChar[0], maxChar = _maxChar[0];

    string S;
    
    for(int i = 0; i < n; ++i){
        S += rnd.next(minChar, maxChar);
    }

    cout << S << "\n";

    return 0;
}