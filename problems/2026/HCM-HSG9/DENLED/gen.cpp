#include "testlib.h"
#include <iostream>

using namespace std;

vector<int> shard(int k, int S, int min_element = 1) {
    if (k * min_element > S) {
        quitf(_fail, "Error: Subtask constraints make the minimum possible sum greater than S.");
    }

    vector<int> a(k, min_element);
    int remaining_sum = S - (k * min_element);

    if (remaining_sum > 0) {
        vector<int> cuts(k - 1);
        for (int i = 0; i < k - 1; ++i) {
            cuts[i] = rnd.next(0, remaining_sum);
        }
        sort(cuts.begin(), cuts.end());

        int prev = 0;
        for (int i = 0; i < k - 1; ++i) {
            a[i] += (cuts[i] - prev);
            prev = cuts[i];
        }
        a[k - 1] += (remaining_sum - prev);
    }

    shuffle(a.begin(), a.end());
    return a;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = rnd.next(opt<int>("min_n", 1), opt<int>("max_n", 1000));
    int k = rnd.next(opt<int>("min_k", 1), opt<int>("max_k", 100));
    int min_val = opt<int>("min_val", 1), max_val = opt<int>("max_val", (int)1e9);
    int bound = opt<int>("bound", -1);
    int subtask = opt<int>("subtask", -1);

    // cout << subtask << "\n";
    cout << n << " " << k << "\n";

    if(bound == -1){
        for(int i = 1; i <= n; ++i){
            cout << rnd.next(min_val, max_val);
            if(i < n) cout << " ";
        }
    }
    else{
        int idx = 1;
        for(int x: shard(n, rnd.next(5000, 10000))){
            cout << x;
            if(idx < n) cout << " ";

            ++idx;
        }
    }

    cout << "\n";
    
    return 0;
}
