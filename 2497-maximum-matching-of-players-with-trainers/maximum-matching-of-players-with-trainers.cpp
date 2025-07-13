class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(t.begin(), t.end());
        sort(p.begin(), p.end());
        int i = 0, j = 0;
        int cnt = 0;
        while (i < p.size() && j < t.size()) {
            if (p[i] <= t[j])
            {
                cnt++;
                i++, j++;
            }
            else 
                j++;
        }
        return cnt;
    }
};