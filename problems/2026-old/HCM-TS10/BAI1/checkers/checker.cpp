#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

signed main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    long long a = inf.readLong();
    long long b = inf.readLong();
    long long c = inf.readLong();
    long long d = inf.readLong();
    long long k = inf.readLong();

    long long jg_x = ans.readLong();
    long long user_x = ouf.readLong();

    if(user_x == -1) {
        if(jg_x != -1) {
            quitf(_wa, "Participant claims no solution, but jury found one.");
        }
        quitf(_ok, "Correct! No solution exists.");
    }

    long long user_y = ouf.readLong();

    if(jg_x == -1) {
        quitf(_wa, "Participant found a solution (%lld, %lld), but jury claims no solution.", user_x, user_y);
    }

    if(user_x < a || user_x > b) {
        quitf(_wa, "Value x = %lld is out of bounds [%lld, %lld].", user_x, a, b);
    }

    if(user_y < c || user_y > d) {
        quitf(_wa, "Value y = %lld is out of bounds [%lld, %lld].", user_y, c, d);
    }

    if((user_x + user_y) % k != 0) {
        quitf(_wa, "Sum x + y = %lld is not divisible by %lld.", user_x + user_y, k);
    }

    quitf(_ok, "Correct! Valid pair (%lld, %lld).", user_x, user_y);

    return 0;
}
