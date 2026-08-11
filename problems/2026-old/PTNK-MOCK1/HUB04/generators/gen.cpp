#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    const int TEST = opt<int>(1);
    const string sub = opt<string>(2);
    
    int n = 1e5, T = 1e9, Q = 1e5;
    int a = rnd.next(1, (int)1e6),
        b = rnd.next(1, (int)1e6);

    if(sub == "sub1"){
        a = b;
    }
    else if(sub == "sub2-small"){
        n = 5;
        Q = 10;
        T = 15;

        a = rnd.next(1, 9);
        b = rnd.next(1, 9);
    }
    else if(sub == "sub2"){
        n = 1000;
        Q = 1000;
    }
    else if(sub == "sub3"){
        // nothing
    }
    else quitf(_fail, "Unknown subtask");

    ensure(n <= T);

    println(n, T, Q, a, b);

    set<int> t;
    while((int)t.size() < n){
        int t_i = rnd.next(0, T);
        t.insert(t_i);
    }

    for(int t_i: t){
        int m_i = rnd.next(1, 2);
        println(t_i, m_i);
    }

    while(Q--){
        int L = rnd.next(0, T);
        if(rnd.next(1, 10) == 1) L = 0;

        int R = rnd.next(L, T);

        println(L, R);
    }

    return 0;
}