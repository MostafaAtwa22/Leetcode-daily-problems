class Solution {
public:
    bool check(vector<int>& a, int i, vector<bool>& vis) {

        if (i < 0 || i >= a.size() || vis[i])
            return false;

        if (a[i] == 0)
            return true;

        vis[i] = true;

        return check(a, i + a[i], vis) ||
               check(a, i - a[i], vis);
    }

    bool canReach(vector<int>& a, int s) {

        vector<bool> vis(a.size(), false);

        return check(a, s, vis);
    }
};