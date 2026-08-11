#include "testlib.h"
#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

int32_t main(int32_t argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int subtask = opt<int>("subtask");
    int mode = opt<int>("mode", 0); 
    
    long long a, b, c, d, k;
    long long MAX_VAL = 1000000000000LL;

    if (subtask == 1) {
        k = rnd.next(1LL, 5000LL);
        a = rnd.next(1LL, 5000LL);
        b = rnd.next(a, 5000LL);
        c = rnd.next(1LL, 5000LL);
        d = rnd.next(c, 5000LL);
    } 
    else if (subtask == 2) {
        k = rnd.next(1LL, MAX_VAL);
        long long mult = rnd.next(1LL, MAX_VAL / k);
        a = b = k * mult;
        c = rnd.next(1LL, MAX_VAL);
        d = rnd.next(c, MAX_VAL);
    } 
    else {
        k = rnd.next(1LL, MAX_VAL);
        a = rnd.next(1LL, MAX_VAL);
        b = rnd.next(a, MAX_VAL);
        c = rnd.next(1LL, MAX_VAL);
        d = rnd.next(c, MAX_VAL);
    }

    if (mode == 2) {
        if (subtask == 2) {
            k = rnd.next(MAX_VAL / 2, MAX_VAL); 
            a = b = k; 
            c = rnd.next(1LL, k / 10); 
            d = rnd.next(k - k / 10, k - 1); 
        } else {
            k = rnd.next(min(MAX_VAL, b + d + 1), MAX_VAL);
        }
    } 
    else if (mode == 1) {
        if (subtask == 2) {
            k = rnd.next(1LL, MAX_VAL);
            long long mult_a = rnd.next(1LL, MAX_VAL / k);
            a = b = k * mult_a;
            c = rnd.next(1LL, k); 
            long long max_mult_c = MAX_VAL / k;
            long long target_c = k * rnd.next(max_mult_c / 2, max_mult_c); 
            d = rnd.next(target_c, MAX_VAL); 
        } else {
            while ((b + d) / k - (a + c - 1) / k <= 0) {
                k = rnd.next(1LL, min(MAX_VAL, b + d));
            }
        }
    }

    cout << a << " " << b << " " << c << " " << d << " " << k << "\n";

    return 0;
}
