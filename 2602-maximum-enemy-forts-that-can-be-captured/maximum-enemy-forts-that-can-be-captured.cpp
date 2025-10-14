class Solution {
public:
    int captureForts(vector<int>& a) {
        vector<int> ar, t;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 1)
                ar.push_back(i);
            else if (a[i] == -1)
                t.push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < ar.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                int cnt = 0;
                if (ar[i] > t[j]) {
                    for (int k = ar[i] - 1; k > t[j]; k--)
                    {
                        if (a[k] != 0) {
                            cnt = 0;
                            break;
                        }
                        else if (a[k] == 0)
                            cnt++;
                    }
                }
                else {
                    for (int k = ar[i] + 1; k < t[j]; k++)
                    {
                        if (a[k] != 0) {
                            cnt = 0;
                            break;
                        }
                        else if (a[k] == 0)
                            cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};