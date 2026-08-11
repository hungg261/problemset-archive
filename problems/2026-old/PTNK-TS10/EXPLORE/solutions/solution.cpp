#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

const int INF = 1e9;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m, k;
vector<string> grid;
int start_x, start_y, target_x, target_y;
vector<pair<int, int>> wolf_positions;
vector<vector<int>> wolf_time;
vector<vector<int>> dist_player;
vector<pair<int, int>> valid_jumps;

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#');
}

void precompute_jumps(int d) {
    for (int jx = -6; jx <= 6; jx++) {
        for (int jy = -6; jy <= 6; jy++) {
            if (jx * jx + jy * jy == d) {
                valid_jumps.push_back({jx, jy});
            }
        }
    }
}

void bfs_wolf() {
    wolf_time.assign(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    for (auto& w : wolf_positions) {
        if (w.first != -1 && w.second != -1) {
            q.push({w.first, w.second});
            wolf_time[w.first][w.second] = 0;
        }
    }
    while (!q.empty()) {
        int x, y; tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && wolf_time[nx][ny] == INF) {
                wolf_time[nx][ny] = wolf_time[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int bfs_player() {
    if (start_x == -1 || start_y == -1 || target_x == -1 || target_y == -1) return -1;
    dist_player.assign(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    dist_player[start_x][start_y] = 0;
    
    while (!q.empty()) {
        int x, y; tie(x, y) = q.front();
        q.pop();
        int t = dist_player[x][y];
        
        if (x == target_x && y == target_y) return t;
        
        for (auto& jump : valid_jumps) {
            int nz = x + jump.first;
            int ntc = y + jump.second;
            
            if (isValid(nz, ntc)) {
                int next_t = t + 1;
                if (next_t < wolf_time[nz][ntc] && dist_player[nz][ntc] == INF) {
                    dist_player[nz][ntc] = next_t;
                    q.push({nz, ntc});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    grid.resize(n);
    
    start_x = start_y = target_x = target_y = -1;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < (int)grid[i].size() && j < m; j++) {
            if (grid[i][j] == 's' || grid[i][j] == 'S') { start_x = i; start_y = j; }
            if (grid[i][j] == 't' || grid[i][j] == 'T') { target_x = i; target_y = j; }
            if (grid[i][j] == 'w' || grid[i][j] == 'W') { wolf_positions.push_back({i, j}); }
        }
    }
    
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        precompute_jumps(d);
    }
    
    sort(valid_jumps.begin(), valid_jumps.end());
    valid_jumps.erase(unique(valid_jumps.begin(), valid_jumps.end()), valid_jumps.end());
    
    bfs_wolf();
    cout << bfs_player() << "\n";
    
    return 0;
}
