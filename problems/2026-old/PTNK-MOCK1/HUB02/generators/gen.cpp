#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    const int TEST = opt<int>(1);
    const string sub = opt<string>(2);

    int T = 1e5, MAXLR = 1e7;
    
    if(sub == "sub1-small"){
        T = 5;
        MAXLR = 100;
    }
    else if(sub == "sub1"){
        T = 100;
        MAXLR = 1000;
    }
    else if(sub == "sub2"){
        T = 100;
        MAXLR = 1e6;
    }
    else if(sub == "sub3"){
        T = 1e5;
        MAXLR = 1e7;
    }
    else quitf(_fail, "Unknown subtask");

    println(T);

    while(T--){
        int L = rnd.next(1, MAXLR);
        int R = rnd.next(L, MAXLR);

        println(L, R);
    }

    return 0;
}