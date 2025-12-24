bool cmp(int & L, int & R) {
    return L > R;
}
class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        sort(c.begin(), c.end(), cmp);
        int sum = 0;
        for (auto & i : a)
            sum += i;
        int i = 0;
        for (; i < c.size(); i++) {
            if (sum <= 0)
                break;
            sum -= c[i];
        }
        return i;
    }
};