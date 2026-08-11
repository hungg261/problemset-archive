#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define int long long

int32_t main(int32_t argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int TEST = opt<int>(1);
    const string sub = opt<string>(2);

    int n = 1, m = 1;
    do{
        if(sub == "sub1-small"){
            n = rnd.next(1, 20);
            m = rnd.next(1, 20);
        }
        else if(sub == "sub1"){
            n = rnd.next(1'000'000, 10'000'000);
            m = rnd.next(1'000'000, 10'000'000);
        }
        else if(sub == "sub2"){
            n = rnd.next((int)5e17, (int)1e18);
            m = rnd.next((int)5e17, (int)1e18);
        }
    }
    while(__gcd(n, m) == 1 && rnd.next(1, 20) != 1);

    println(n, m);

    return 0;
}