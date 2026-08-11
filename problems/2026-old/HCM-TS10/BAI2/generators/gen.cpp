#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n_val, m_val;
vector<int> X, Y;
vector<int> cleanX, cleanY;

int count_robots(const vector<int>& V, int w) {
    if (V.empty()) return 0;
    int cnt = 1;
    int last = V[0];
    for (size_t i = 1; i < V.size(); ++i) {
        if (V[i] > last + w) {
            cnt++;
            last = V[i];
        }
    }
    return cnt;
}

bool check(int w) {
    long long total = (long long)count_robots(cleanX, w) + count_robots(cleanY, w);
    return total <= n_val;
}

int solve() {
    cleanX = X;
    cleanY = Y;
    
    sort(cleanX.begin(), cleanX.end());
    cleanX.erase(unique(cleanX.begin(), cleanX.end()), cleanX.end());
    
    sort(cleanY.begin(), cleanY.end());
    cleanY.erase(unique(cleanY.begin(), cleanY.end()), cleanY.end());

    int low = 0, high = 1e9, ans = 1e9;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int subtask = opt<int>("subtask");
    int max_n = opt<int>("n");
    int max_m = opt<int>("m");
    int ran = opt<int>("r", 0);

    if (ran) {
        m_val = max_m;
        int pct = rnd.next(1, 100);
        if (pct <= 20) {
            n_val = rnd.next(m_val, max_n);
        } else if (pct <= 50) {
            n_val = rnd.next(2, min(20, m_val - 1));
        } else {
            n_val = rnd.next(max(2, m_val / 10), m_val - 1);
        }
    } else {
        n_val = max_n;
        m_val = max_m;
    }

    if (subtask == 1) {
        n_val = 2;
    }

    X.resize(m_val);
    Y.resize(m_val);

    if (subtask == 2) {
        int x_fixed = rnd.next(0, 1000000000);
        int loop_cnt = 0;
        int force_zero = rnd.next(1, 100) <= 50;

        while (true) {
            loop_cnt++;
            if (loop_cnt > 5) {
                loop_cnt = 0;
                if (ran) {
                    m_val = rnd.next(1, max_m);
                    int pct = rnd.next(1, 100);
                    if (pct <= 20) {
                        n_val = rnd.next(m_val, max_n);
                    } else if (pct <= 50) {
                        n_val = rnd.next(2, min(20, m_val - 1));
                    } else {
                        n_val = rnd.next(max(2, m_val / 10), m_val - 1);
                    }
                } else {
                    n_val = max_n;
                    m_val = max_m;
                }
                X.resize(m_val);
                Y.resize(m_val);
                x_fixed = rnd.next(0, 1000000000);
                force_zero = rnd.next(1, 100) <= 50;
            }

            if (force_zero) {
                int max_distinct_y = min(m_val, max(1, n_val - 1));
                vector<int> distinct_y(max_distinct_y);
                for (int i = 0; i < max_distinct_y; ++i) {
                    distinct_y[i] = rnd.next(0, 1000000000);
                }
                for (int i = 0; i < m_val; ++i) {
                    X[i] = x_fixed;
                    Y[i] = distinct_y[rnd.next(0, max_distinct_y - 1)];
                }
            } else {
                long long current_y = rnd.next(1, 10);
                for (int i = 0; i < m_val; ++i) {
                    X[i] = x_fixed;
                    Y[i] = (int)current_y;
                    current_y += rnd.next(500, 1000);
                }
            }

            int w = solve();

            if (force_zero && w != 0) {
                continue;
            }

            if (w <= 1000) {
                break;
            }
        }
    } else {
        for (int i = 0; i < m_val; ++i) {
            X[i] = rnd.next(0, 1000000000);
            Y[i] = rnd.next(0, 1000000000);
        }
    }

    vector<pair<int, int>> points(m_val);
    for (int i = 0; i < m_val; ++i) {
        points[i] = {X[i], Y[i]};
    }
    shuffle(points.begin(), points.end());

    println(n_val, m_val);
    for (int i = 0; i < m_val; ++i) {
        println(points[i].first, points[i].second);
    }

    return 0;
}
