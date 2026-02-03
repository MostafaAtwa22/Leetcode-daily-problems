class Solution {
public:
    bool isTrionic(vector<int>& a) {
        int cnt = 0;
        int start = a[0];
        bool flg = true;
        int n = a.size();
        int sz = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == start)
                return false;
            if (a[i] < start && flg == true) {
                if (sz == 1)
                    return false;
                flg = false;
                cnt++;
                sz = 1;
            }
            else if (a[i] > start && flg == false) {
                if (sz == 1)
                    return false;
                flg = true;
                cnt++;
                sz = 1;
            }
            sz++;
            start = a[i];
        }
        return cnt == 2;
    }
};