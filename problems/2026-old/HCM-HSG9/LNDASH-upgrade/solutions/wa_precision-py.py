import math
import bisect

N,T,Q = map(int,input().split())
changes = {}
for _ in range(N):
    t,c = input().split()
    changes[int(t)] = c

events = sorted(changes.items())
events = [(1,'-')] + events + [(T+1,'-')]

times = [e[0] for e in events]
cmds  = [e[1] for e in events]

psum = [0.0]
for i in range(len(events)-1):
    length = events[i+1][0] - events[i][0]
    d = 1.0 if cmds[i]=='-' else math.sqrt(2)
    psum.append(psum[-1] + length*d)

for _ in range(Q):
    L,R = map(int,input().split())
    l_idx = bisect.bisect_right(times, L) -1
    r_idx = bisect.bisect_right(times, R) -1

    total = psum[r_idx] - psum[l_idx]
    total += (times[l_idx+1]-L) * (1.0 if cmds[l_idx]=='-' else math.sqrt(2))
    total -= (times[r_idx+1]-R) * (1.0 if cmds[r_idx]=='-' else math.sqrt(2))

    print(f"{total:.6f}")