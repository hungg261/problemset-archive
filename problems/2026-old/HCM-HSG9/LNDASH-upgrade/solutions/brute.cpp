#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N, T, Q;
    cin >> N >> T >> Q;
    vector<double> steps(T + 1, 1.0);
    for (int i = 0; i < N; ++i) {
        int c; char s;
        cin >> c >> s;
        double d = (s == '-') ? 1.0 : sqrt(2.0);
        for (int j = c; j <= T; ++j) steps[j] = d;
    }
    vector<double> pref(T + 1, 0.0);
    pref[0] = steps[0];
    for (int i = 1; i <= T; ++i) pref[i] = pref[i-1] + steps[i];
    
    cout << fixed << setprecision(6);
    while (Q--) {
        int L, R;
        cin >> L >> R;
        if (L >= R) cout << "0.000000\n";
        else cout << pref[R - 1] - (L > 0 ? pref[L-1] : 0) << "\n";
    }
    return 0;
}
