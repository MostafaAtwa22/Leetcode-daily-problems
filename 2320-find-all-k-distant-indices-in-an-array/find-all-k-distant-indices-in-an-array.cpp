class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int key, int k) {
        vector<int> ans, b;
        for (int i = 0; i < a.size(); i++)
            if (a[i] == key)
                b.push_back(i);
        if (b.empty())
            return {};
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                if (abs(i - b[j]) <= k)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};