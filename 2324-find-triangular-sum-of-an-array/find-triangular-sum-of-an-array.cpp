class Solution {
public:
    int triangularSum(vector<int>& a) {
        int n = a.size();
        deque<int> dq;
        for (auto i : a)
            dq.push_back(i);
        int j = 1;
        while (dq.size() > 1) {
            int x = (dq[1] + dq[0]) % 10;
            if (dq[0] + dq[1] < 10)
                x = dq[1] + dq[0];
            dq.push_back(x);
            dq.pop_front();
            j++;
            if (j == n) {
                n--;
                dq.pop_front();
                j = 1;
            }
        }   
        return dq[0];
    }
};