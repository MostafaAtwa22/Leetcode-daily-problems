int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    bool valid(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    bool bfs(vector<vector<int>>& a, int h) {
        int n = a.size(), m = a[0].size();
        
        // Store: {remaining_health, row, col}
        // Using max-heap for health (we want highest health first)
        priority_queue<tuple<int, int, int>> pq;

        int startHealth = h - a[0][0];
        if (startHealth <= 0) return false;  // Need health > 0 to start
        
        pq.push({startHealth, 0, 0});
        
        // Track maximum health we've reached each cell with
        vector<vector<int>> maxHealth(n, vector<int>(m, -1));
        maxHealth[0][0] = startHealth;
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int health = get<0>(top);
            int r = get<1>(top);
            int c = get<2>(top);

            // If we've already found a better way to this cell, skip
            if (health < maxHealth[r][c]) continue;

            // Reached destination
            if (r == n - 1 && c == m - 1) {
                return health > 0;
            }
            
            // If health is 0 or less, can't move further
            if (health <= 0) continue;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (valid(nr, nc, n, m)) {
                    int newHealth = health - a[nr][nc];
                    // Only push if health > 0 and this is better than previous
                    if (newHealth > 0 && newHealth > maxHealth[nr][nc]) {
                        maxHealth[nr][nc] = newHealth;
                        pq.push({newHealth, nr, nc});
                    }
                }
            }
        }
        return false;
    }

    bool findSafeWalk(vector<vector<int>>& a, int h) {
        return bfs(a, h);
    }
};