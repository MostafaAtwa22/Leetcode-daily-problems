const int N = 1e5 + 2;
class Solution {
public:
    vector <int> graph[N];
    int visitedDir[N];
    bool dfsDir (int node)
    {
        visitedDir[node] = 1;
        bool res = false;
        for (auto child : graph[node])
        {
            if (visitedDir[child] == 1) // visit it and there is a loop
                return true;
            else if (visitedDir[child] == 0) // it's not visited yet
                res |= dfsDir(child);
        }
        visitedDir[node] = 2; // visit and finish the DFS of it
        return res;
    }

    bool canFinish(int n, vector<vector<int>>& a) {
        for (int i = 0; i < a.size(); i++) {
            graph[a[i][0]].push_back(a[i][1]);
        }
        for (int i = 0; i < n; i++) {
            if (dfsDir(i))
                return false;
        }
        return true;
    }
};