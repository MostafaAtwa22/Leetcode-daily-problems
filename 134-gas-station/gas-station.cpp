class Solution {
public:
    bool check (vector<int> &a, int start)
    {
        int sum = 0;
        int i = start;
        int n = a.size();
        while (true)
        {
            sum += a[i % n];
            i++;
            if (sum < 0)
                return false;
            if ((i % n) == start)
                break;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            sum += (gas[i] - cost[i]);
            a[i] = gas[i] - cost[i];
        }
        if (sum < 0)    
            return -1;
        int total = 0, ind = 0;
        for (int i = 0; i < n; i++)
        {
            total += a[i];
            cout << total << '\n';
            if (total < 0)
            {
                total = 0;
                ind = i + 1;
            }
        }
        return ind;
    }
};