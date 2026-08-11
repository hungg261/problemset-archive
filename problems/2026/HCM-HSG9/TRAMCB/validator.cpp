#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    long long n = inf.readLong(1LL, (long long)1e18, "n~");
    inf.readSpace();
    long long m = inf.readLong(1LL, (long long)1e18, "m~");
    inf.readEoln();

    inf.readEof();

    return 0;
}
