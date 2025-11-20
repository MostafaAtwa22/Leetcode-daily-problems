bool cmp(vector<int>& l, vector<int>& r) {
    if (l[1] == r[1])
        return l[0] > r[0];
    return l[1] < r[1];
}
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& b) {
        sort(b.begin(), b.end(), cmp);
        int cnt = 0;
        int p1 = -1, p2 = -1;
        for (auto i : b) {
            int l = i[0], r = i[1];
            if (p2 < l) {
                cnt += 2;
                p1 = r - 1, p2 = r;
            }
            else if (p1 < l) {
                cnt++;
                p1 = p2, p2 = r;
            }
        }
        return cnt;
    }
};