#include "testlib.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m, k, w_opt, d_opt, killer;
vector<string> grid;
int start_x, start_y, target_x, target_y;
vector<pair<int, int>> wolf_positions;
vector<vector<int>> wolf_time;
vector<pair<int, int>> valid_jumps;

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

bool has_path() {
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    if (start_x == -1 || start_y == -1) return false;
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;
    while (!q.empty()) {
        int x, y; tie(x, y) = q.front();
        q.pop();
        if (x == target_x && y == target_y) return true;
        for (auto& jump : valid_jumps) {
            int nz = x + jump.first;
            int ntc = y + jump.second;
            if (isValid(nz, ntc) && dist[nz][ntc] == INF) {
                if (dist[x][y] + 1 < wolf_time[nz][ntc]) {
                    dist[nz][ntc] = dist[x][y] + 1;
                    q.push({nz, ntc});
                }
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    n = opt<int>(2);
    m = opt<int>(3);
    k = opt<int>(4);
    w_opt = opt<int>(5);
    d_opt = opt<int>(6);
    killer = opt<int>(7);
    
    vector<int> d_list;
    if (d_opt >= 1) {
        k = 1;
        d_list.push_back(d_opt);
    } else {
        vector<int> all_d;
        for (int i = 1; i <= 26; i++) all_d.push_back(i);
        shuffle(all_d.begin(), all_d.end());
        for (int i = 0; i < k; i++) d_list.push_back(all_d[i]);
        sort(d_list.begin(), d_list.end());
    }
    
    for (int d : d_list) {
        for (int jx = -6; jx <= 6; jx++) {
            for (int jy = -6; jy <= 6; jy++) {
                if (jx * jx + jy * jy == d) {
                    valid_jumps.push_back({jx, jy});
                }
            }
        }
    }
    sort(valid_jumps.begin(), valid_jumps.end());
    valid_jumps.erase(unique(valid_jumps.begin(), valid_jumps.end()), valid_jumps.end());
    
    int wall_pct = (d_opt == 1 && w_opt == 0) ? 0 : ((killer == 1) ? rnd.next(5, 12) : rnd.next(15, 30));
    if (killer == -2) wall_pct = 0; 

    int attempts = 0;
    while (attempts < 1000) {
        grid.assign(n, string(m, '.'));
        wolf_positions.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rnd.next(100) < wall_pct) {
                    grid[i][j] = '#';
                }
            }
        }
        
        vector<pair<int, int>> free_cells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') free_cells.push_back({i, j});
            }
        }
        
        if (free_cells.size() < 2) {
            attempts++;
            continue;
        }
        
        shuffle(free_cells.begin(), free_cells.end());
        start_x = free_cells[0].first; start_y = free_cells[0].second;
        target_x = free_cells[1].first; target_y = free_cells[1].second;
        
        int max_wolves = (int)free_cells.size() - 2;
        int num_wolves = 0;
        if (w_opt == -1) {
            num_wolves = (killer == 1) ? rnd.next(2, min(5, max_wolves)) : rnd.next(0, min(3, max_wolves));
        } else {
            num_wolves = min(w_opt, max_wolves);
        }
        num_wolves = max(0, num_wolves);
        
        if (killer == 1 && num_wolves > 0) {
            int d_idx = rnd.next((int)d_list.size());
            int target_d = d_list[d_idx];
            vector<pair<int, int>> paths_d;
            for (int jx = -6; jx <= 6; jx++) {
                for (int jy = -6; jy <= 6; jy++) {
                    if (jx * jx + jy * jy == target_d) {
                        paths_d.push_back({jx, jy});
                    }
                }
            }
            if (!paths_d.empty()) {
                auto p = paths_d[rnd.next((int)paths_d.size())];
                int tx = start_x + p.first;
                int ty = start_y + p.second;
                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    target_x = tx;
                    target_y = ty;
                    grid[target_x][target_y] = '.';
                }
            }
            
            vector<pair<int, int>> adj_t;
            for (int i = 0; i < 4; i++) {
                int nx = target_x + dx[i];
                int ny = target_y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                    adj_t.push_back({nx, ny});
                }
            }
            
            int added_wolves = 0;
            while (!adj_t.empty() && added_wolves < num_wolves) {
                int idx = rnd.next((int)adj_t.size());
                if (adj_t[idx] != make_pair(start_x, start_y)) {
                    wolf_positions.push_back(adj_t[idx]);
                    added_wolves++;
                }
                adj_t.erase(adj_t.begin() + idx);
            }
            
            int ptr = 2;
            while (added_wolves < num_wolves && ptr < (int)free_cells.size()) {
                if (free_cells[ptr] != make_pair(target_x, target_y) && free_cells[ptr] != make_pair(start_x, start_y)) {
                    wolf_positions.push_back(free_cells[ptr]);
                    added_wolves++;
                }
                ptr++;
            }
        } else {
            int ptr = 2;
            int added_wolves = 0;
            while (added_wolves < num_wolves && ptr < (int)free_cells.size()) {
                wolf_positions.push_back(free_cells[ptr]);
                added_wolves++;
                ptr++;
            }
        }
        
        grid[start_x][start_y] = 's';
        grid[target_x][target_y] = 't';
        for (auto& w : wolf_positions) {
            grid[w.first][w.second] = 'w';
        }
        
        bfs_wolf();
        if (has_path() || num_wolves == 0) break;
        attempts++;
    }
    
    cout << n << " " << m << " " << k << "\n";
    for (int i = 0; i < n; i++) {
        cout << grid[i] << "\n";
    }
    for (int i = 0; i < k; i++) {
        cout << d_list[i] << (i == k - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}
