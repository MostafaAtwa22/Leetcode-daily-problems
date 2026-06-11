const int mod = 1e9 + 7;
vector<int> g[100005];
bool vis[100005];

class Solution {
public:
    int getMaxHeight(int u) {
        vis[u] = true;
        int maxDepth = 0;
        for (auto v : g[u]) {
            if (!vis[v])
                maxDepth = max(maxDepth, getMaxHeight(v) + 1);
        }
        return maxDepth;
    }
    
    long long powerMod(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    int assignEdgeWeights(vector<vector<int>>& a) {
        // Clear arrays
        for (int i = 0; i <= 100000; i++) {
            g[i].clear();
            vis[i] = false;
        }
        
        // Build graph
        for (auto i : a) {
            int u = i[0], v = i[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        int height = getMaxHeight(1);
        
        // Calculate 2^(height-1) mod mod
        long long result = powerMod(2, height - 1, mod);
        
        return (int)result;
    }
};