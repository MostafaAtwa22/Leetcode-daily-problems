class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, total = 0;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (gas[i] - cost[i]);
            total += gas[i] - cost[i];
            if (sum < 0)
            {
                sum = 0;
                ind = i + 1;
            }
        }
        return ind == n || total < 0 ? -1 : ind;
    }
};