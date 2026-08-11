#include <iostream>
#include <vector>
#include <queue>
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
vector<int> target_d;

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#');
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
        
        for (int z = 0; z < n; z++) {
            for (int tc = 0; tc < m; tc++) {
                if (!isValid(z, tc)) continue;
                
                int sq_dist = (z - x) * (z - x) + (tc - y) * (tc - y);
                bool valid_jump = false;
                for (int i = 0; i < k; i++) {
                    if (sq_dist == target_d[i]) {
                        valid_jump = true;
                        break;
                    }
                }
                
                if (valid_jump) {
                    int next_t = t + 1;
                    if (next_t < wolf_time[z][tc] && dist_player[z][tc] == INF) {
                        dist_player[z][tc] = next_t;
                        q.push({z, tc});
                    }
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
    
    target_d.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> target_d[i];
    }
    
    bfs_wolf();
    cout << bfs_player() << "\n";
    
    return 0;
}
