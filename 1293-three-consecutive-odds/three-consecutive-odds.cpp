class Solution {
public:
    // github
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++)
            if (i - 1 >= 0 && i + 1 < arr.size() && 
            (arr[i] & 1) && (arr[i - 1] & 1) && (arr[i + 1] & 1))
                return true;
        return false;
    }
};