class FindSumPairs {
public:
    unordered_map<int, int> mp;
    vector<int> a, b;
    int n;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto i : nums2)
            mp[i]++;
        a = nums1;
        b = nums2;
        n = a.size();
    }
    
    void add(int index, int val) {
        int v = b[index];
        mp[v]--;
        b[index] += val;
        mp[b[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += mp[tot - a[i]];
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */