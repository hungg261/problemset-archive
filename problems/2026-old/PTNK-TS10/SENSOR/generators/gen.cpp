#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>(2);
    int MAXVAL = opt<int>(3);
    int mode = opt<int>(4);

    vector<long long> a(n + 1, 0);

    if(mode == 0){
        for(int i = 1; i <= n; ++i){
            a[i] = rnd.next(-MAXVAL, MAXVAL);
        }
    }
    else{
        vector<long long> f(n + 1, 0);
        int num_groups = rnd.next(2, max(2, n / 10));
        vector<long long> pool(num_groups);
        for(int i = 0; i < num_groups; ++i){
            pool[i] = rnd.next(-1LL * MAXVAL * MAXVAL, 1LL * MAXVAL * MAXVAL);
        }

        f[0] = rnd.next(-1LL * MAXVAL, 1LL * MAXVAL);
        for(int i = 1; i <= n; ++i){
            f[i] = pool[rnd.next(0, num_groups - 1)];
        }

        for(int i = 1; i <= n; ++i){
            long long P_i = f[i] + 1LL * i * i + i;
            long long P_prev = f[i - 1] + 1LL * (i - 1) * (i - 1) + (i - 1);
            a[i] = P_i - P_prev;
            if(a[i] > MAXVAL) a[i] = MAXVAL - rnd.next(0, 100);
            if(a[i] < -MAXVAL) a[i] = -MAXVAL + rnd.next(0, 100);
        }
    }

    cout << n << "\n";
    for(int i = 1; i <= n; ++i){
        cout << a[i];
        if(i < n) cout << " ";
    }

    cout << "\n";

    return 0;
}
