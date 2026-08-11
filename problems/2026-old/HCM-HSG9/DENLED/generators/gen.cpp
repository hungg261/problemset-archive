#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define int long long

vector<int> reshard(int count, int total){
    if(count > total) throw runtime_error("weird at reshard()");
    if(count <= 0) return {};
    if(count == 1) return {total};
    
    set<int> positions;
    while((int)positions.size() < count - 1)
        positions.insert(rnd.next(1LL, total - 1));
    
    vector<int> parts;
    int last = 0;
    for (int p: positions) {
        parts.push_back(p - last);
        last = p;
    }
    parts.push_back(total - last);
    return parts;
}

int32_t main(int32_t argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int TEST = opt<int>(1);
    const string sub = opt<string>(2);
    const string param = opt<string>(3);

    int n = 1000, k = 100;
    int MAX = 1'000'000'000;
    if(sub == "sub1"){
        n = rnd.next(5, 20);
        k = rnd.next(3, 60);
        MAX = 50;
        if(param == "max") n = 20;
    }
    else if(sub == "sub2"){
        n = rnd.next(500, 1000);
        k = 2;
        if(param == "max") n = 1000;
    }
    else if(sub == "sub3" || sub == "sub4"){
        n = rnd.next(900, 1000);
        k = rnd.next(TEST, 100LL);
        if(param == "max") n = 1000;
    }

    println(n, k);

    if(sub == "sub3"){
        for(int ele: reshard(n, rnd.next(9'800, 10'000))){
            cout << ele << " ";
        }
    }
    else for(int i = 1; i <= n; ++i){
        cout << rnd.next(1LL, MAX) << " ";
    }

    cout << endl;

    return 0;
}