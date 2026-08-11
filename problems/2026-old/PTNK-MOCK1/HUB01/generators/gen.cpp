#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    #define int long long
    
    const int TEST = opt<int>(1);
    
    int MAXVAL = 1e9;
    int n = rnd.next(1LL, (int)1e5), D = rnd.next(1LL, (int)1e9);

    if(TEST == 1) n = 1;
    else if(TEST == 2) n = 1, D = 0;
    else if(TEST <= 5) D = 0;
    else if(TEST <= 7) MAXVAL = 10, D = rnd.next(0LL, (int)MAXVAL + 3);
    else if(TEST <= 10) MAXVAL = 1000, D = rnd.next(0LL, (int)MAXVAL + 30);
    
    if(TEST == 10 || TEST == 11) D = 0;
    if(TEST == 12) D = 1e9;
    if(TEST > 10) n = 1e5;

    println(n, D);
    for(int i = 1; i <= n; ++i){
        cout << rnd.next(1LL, MAXVAL);
        if(i < n) cout << " ";
    }
    cout << "\n";

    return 0;
}