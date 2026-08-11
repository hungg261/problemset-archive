#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    const int TEST = opt<int>(1);
    const string sub = opt<string>(2);
    
    int m = 500, n = 500, k = rnd.next(3, 199);

    if(sub == "sub1"){
        m = rnd.next(1, 10);
        n = rnd.next(1, 10);
        k = rnd.next(2, 10);
    }
    else if(sub == "sub2"){
        m = rnd.next(100, 500);
        n = rnd.next(100, 500);
        k = 1;
    }
    else if(sub == "sub3"){
        // nothing
    }
    else quitf(_fail, "Unknown subtask");

    println(m, n, k);
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cout << rnd.next(1, 1'000'000);
            if(j < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}