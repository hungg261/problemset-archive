#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = rnd.next(opt<int>("min_n", 2), opt<int>("max_n", (int)3e5));
    int m = rnd.next(opt<int>("min_m", 3), opt<int>("max_m", (int)1e9));
    int special = opt<int>("special", 0);
    if(special == -1) special = rnd.next(1, 3) > 1 ? 0 : 1;

    println(n, m);

    if(special){
        for(int i = 1; i <= n; ++i){
            if(m - i + 1 >= 0){
                if(i & 1) println(i, m - i + 1);
                else println(m - i + 1, i);
            }
            else println(rnd.next(0, m), rnd.next(0, m));
        }
        return 0;
    }
    
    for(int i = 1; i <= n; ++i){
        int x = rnd.next(0, m);
        int y = rnd.next(0, m);

        println(x, y);
    }
    
    return 0;
}
