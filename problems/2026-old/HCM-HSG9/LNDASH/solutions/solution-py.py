import sys
import math
import bisect
from decimal import Decimal, getcontext, ROUND_HALF_UP

getcontext().prec = 100

def solve():
    data = sys.stdin.read().split()
    if not data: return
    
    N = int(data[0])
    T = int(data[1])
    Q = int(data[2])
    
    SQRT2 = Decimal(2).sqrt()
    ONE = Decimal(1)
    
    changes = {0: '-'}
    ptr = 3
    for _ in range(N):
        t_val = int(data[ptr])
        s_val = data[ptr+1]
        changes[t_val] = s_val
        ptr += 2
        
    sorted_times = sorted(changes.keys())
    segs = []
    curr_p = Decimal(0)
    
    for i in range(len(sorted_times)):
        t = sorted_times[i]
        if i > 0:
            pt = sorted_times[i-1]
            pv = ONE if changes[pt] == '-' else SQRT2
            curr_p += pv * (t - pt)
        
        v_curr = ONE if changes[t] == '-' else SQRT2
        segs.append((t, v_curr, curr_p))

    times_only = [s[0] for s in segs]

    def get_S(X):
        if not segs or X <= segs[0][0]: return Decimal(0)
        idx = bisect.bisect_right(times_only, X) - 1
        ts, v, pb = segs[idx]
        return pb + v * (X - ts)

    output = []
    for _ in range(Q):
        if ptr + 1 >= len(data): break
        L = int(data[ptr])
        R = int(data[ptr+1])
        ptr += 2
        if L >= R:
            output.append("0.000000")
        else:
            res = get_S(R) - get_S(L)
            output.append("{:.6f}".format(res.quantize(Decimal("0.000001"), rounding=ROUND_HALF_UP)))
    
    sys.stdout.write("\n".join(output) + "\n")

if __name__ == "__main__":
    solve()
