class Solution {
public:
    bool check (vector<int> & a) {
        for (int i = 1; i < a.size(); i++) 
            if (a[i] < a[i - 1])
                return false;
        return true;
    }
    void conv(vector<int> & a) {
        int mn = INT_MAX;
        int idx = 0;
        for (int i = 0; i < a.size() - 1; i++) {
            if (mn > a[i] + a[i + 1]) {
                mn = a[i] + a[i + 1];
                idx = i;
            }
        }
        a[idx + 1] = mn;
        a.erase(a.begin() + idx, a.begin() + idx + 1);
    }
    int minimumPairRemoval(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!check(a)) {
                cnt++;
                conv(a);
            } else {
                break;
            }
        }
        return cnt;
    }
};