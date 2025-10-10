class Solution {
public:
    long long findTheArrayConcVal(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        long long ans = 0;

        while (l < r) {
            string str = to_string(a[l]) + to_string(a[r]);
            ans += stol(str);
            l++, r--;
        }
        return ans + (((int)a.size() % 2) ? a[a.size() / 2] : 0);    
    }
};