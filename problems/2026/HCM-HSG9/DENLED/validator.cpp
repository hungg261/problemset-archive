#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    // int subtask = inf.readInt(); inf.readEoln();
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int k = inf.readInt(1, 100, "k~");
    inf.readEoln();

    long long sum = 0;
    for(int i = 1; i <= n; ++i){
        int a_i = inf.readInt(1, (int)1e9, format("a[%d]", i));
        if(i < n) inf.readSpace();

        sum += a_i;
    }

    // if(subtask == 3 && !(sum <= (int)1e4)) quitf(_fail, "Subtask 3: sum > 1e4");

    inf.readEoln();
    inf.readEof();
    
    return 0;
}
