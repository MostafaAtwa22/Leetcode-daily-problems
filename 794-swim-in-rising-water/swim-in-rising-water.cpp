class Solution {
public:
    int swimInWater(vector<vector<int>>& a) {
        int n = a.size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        bool vis[55][55];
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;
        
        pq.push({a[0][0], {0, 0}});
        vis[0][0] = true;
        while (!pq.empty()) {
            auto[h, x] = pq.top();
            pq.pop();
            int r = x.first, c = x.second;
            if (r == n - 1 && c == n - 1)
                return h;
            for (int i = 0; i < 4; i++) {
                int newR = r + dx[i];
                int newC = c + dy[i];
                if (newR < 0 || newR >= n || newC < 0 || newC >= n || vis[newR][newC])
                    continue;
                vis[newR][newC] = true;
                pq.push({max(a[newR][newC], h), {newR, newC}});
            } 
        }
        return pq.top().first;
    }
};