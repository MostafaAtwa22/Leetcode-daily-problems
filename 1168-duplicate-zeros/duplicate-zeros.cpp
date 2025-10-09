class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> a;
        for (auto i : arr) {
            a.push_back(i);
            if (!i)
                a.push_back(i);
        }
        for (int i = 0; i < arr.size(); i++)
            arr[i] = a[i];
    }
};