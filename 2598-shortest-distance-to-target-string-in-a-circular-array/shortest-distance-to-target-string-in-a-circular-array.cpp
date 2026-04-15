class Solution {
public:
    int closestTarget(vector<string>& a, string t, int st) {
        vector<string> arr;
        for (int i = 0; i < 3; i++) {
            for (auto j : a)
                arr.push_back(j);
        }
        int idx = a.size() + st;
        int ans = INT_MAX;
        for (int i = idx; i < arr.size(); i++) {
            if (t == arr[i])    
                ans = min(ans, i - idx);
        }
        for (int i = idx; i >= 0; i--)
            if (t == arr[i])
                ans = min (ans, idx - i);
        
        return ans == INT_MAX ? -1 : ans;
    }
};