class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        priority_queue<pair<int,int>> max;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min;
        for (int i = 0; i < p.size(); i++) {
            min.push({c[i], p[i]});
        }
        for (int i = 0; i < k; i++) {
            while(!min.empty() && min.top().first <= w) {
                max.push({min.top().second, min.top().first});
                min.pop();
            }
            if (max.empty())
                break;
            w += max.top().first;
            max.pop();
        }
        return w;
    }
};