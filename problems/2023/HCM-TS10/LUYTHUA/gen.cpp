#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 2000000000LL;

long long calc_power(int p) {
    long long base = p / 10;
    long long exp = p % 10;
    
    if (base == 0 && exp == 0) return 1;
    long long res = 1;
    for (int i = 0; i < exp; ++i) {
        if (res > INF / base) return INF;
        res *= base;
    }
    return res;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = rnd.next(opt<int>("min_n", 1), opt<int>("max_n", 20));
    int min_val = 10;
    int max_val = opt<int>("max_val", 10000) - 1;
    
    ensure(min_val <= max_val);

    long long max_sum = 1000000000LL - 1;
    long long current_sum = 0;
    vector<int> result;

    for (int i = 1; i <= n; ++i) {
        long long rem_budget = (max_sum - current_sum) / (n - i + 1);
        
        vector<int> candidates;
        for (int val = min_val; val <= max_val; ++val) {
            long long pow_val = calc_power(val);
            if (pow_val <= rem_budget) {
                candidates.push_back(val);
            }
        }

        if (candidates.empty()) {
            for (int val = min_val; val <= max_val; ++val) {
                long long pow_val = calc_power(val);
                if (current_sum + pow_val <= max_sum) {
                    candidates.push_back(val);
                }
            }
        }

        int chosen = candidates[rnd.next(0, (int)candidates.size() - 1)];
        result.push_back(chosen);
        current_sum += calc_power(chosen);
    }

    println(n);
    for (int i = 0; i < n; ++i) {
        println(result[i]);
    }
    
    return 0;
}