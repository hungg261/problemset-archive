#include "testlib.h"
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main(int32_t argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int min_val = opt<int>("min_val", 1), max_val = opt<int>("max_val", (int)1e18);
    int is_g = opt<int>("is_g", -1); // 1: gcd != 1, 0: gcd == 1, -1: random
    if(is_g == -1) is_g = rnd.next(0, 1);

    int n = -1, m = -1;

    if (is_g == 1) {
        if (max_val <= 2 || min_val == max_val) {
            quitf(_fail, "Error: Range constraints make GCD != 1 mathematically impossible.");
        }

        int attempts = 0;
        while (true) {
            if (++attempts > 10000) {
                quitf(_fail, "Error: Range is too tight to easily pick distinct multipliers.");
            }

            int max_possible_g = max_val / 2;
            if (max_possible_g < 2) max_possible_g = max_val;

            int g = rnd.next(2LL, max_possible_g);
            int min_mult = (min_val + g - 1) / g;
            int max_mult = max_val / g;

            if (min_mult < max_mult) {
                int mult_n = rnd.next(min_mult, max_mult);
                int mult_m = rnd.next(min_mult, max_mult);
                
                if (mult_n == mult_m) {
                    if (mult_n > min_mult) mult_m = mult_n - 1;
                    else if (mult_n < max_mult) mult_m = mult_n + 1;
                    else continue; 
                }

                n = g * mult_n;
                m = g * mult_m;
                break;
            }
        }
    } else {
        int attempts = 0;
        do {
            if (++attempts > 10000) {
                quitf(_fail, "Error: Timeout trying to find a pair with GCD == 1.");
            }
            n = rnd.next(min_val, max_val);
            m = rnd.next(min_val, max_val);
        } while (__gcd(n, m) != 1 || n == m); 
    }

    println(n, m);
    return 0;
}
