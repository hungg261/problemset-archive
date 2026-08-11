#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int subtask = opt<int>(2, 4);
    
    long long max_n = 1000000000000000000LL;
    int q = 10;
    
    if(subtask == 1){
        max_n = 1000LL;
        q = 10;
    } else if(subtask == 2){
        max_n = 1000000LL;
        q = 10;
    } else if(subtask == 3){
        max_n = 1000000000000LL;
        q = 10;
    }
    
    println(q);
    
    vector<long long> highly_composite ={
        720720, 1441440, 2162160, 3603600, 7207200, 
        14414400, 21621600, 32432400, 43243200, 735134400,
        6983776800LL, 9675973200LL, 13967553600LL, 23279256000LL,
        53970221342416000LL, 720720000000000000LL, 922337203685477580LL
    };
    
    for(int i = 0; i < q; ++i){
        int type = rnd.next(1, 100);
        long long n = 1;
        
        if(type <= 30 && !highly_composite.empty()){
            n = highly_composite[rnd.next(0, (int)highly_composite.size() - 1)];
            while(n > max_n){
                n /= 2;
            }
            if(n == 0) n = 1;
        } else if(type <= 50){
            n = 1LL << rnd.next(0, subtask == 1 ? 9 :(subtask == 2 ? 19 :(subtask == 3 ? 39 : 59)));
        } else if(type <= 70){
            long long root = rnd.next(1LL, (long long)sqrt(max_n));
            n = root * root;
        } else{
            n = rnd.next(1LL, max_n);
        }
        
        if(n < 1) n = 1;
        if(n > max_n) n = max_n;
        
        println(n);
    }
    
    return 0;
}
