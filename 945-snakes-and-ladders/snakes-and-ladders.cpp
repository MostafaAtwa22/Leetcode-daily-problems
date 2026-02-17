class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        auto getPos = [&](int num) {
            int r = (num - 1) / n;
            int c = (num - 1) % n;
            int row = n - 1 - r;
            if (r % 2 == 1)
                c = n - 1 - c;
            return pair<int,int>{row, c};
        };

        vector<bool> vis(n * n + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int cur = q.front();
                q.pop();

                if (cur == n * n)
                    return moves;

                for (int d = 1; d <= 6; d++) {
                    int nxt = cur + d;
                    if (nxt > n * n) continue;

                    auto [r, c] = getPos(nxt);
                    if (board[r][c] != -1)
                        nxt = board[r][c];

                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
