class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        unordered_map<int, bool> mp;
        int cnt = 0;
        for (int i = 0; i < f.size(); i++) {
            bool flg = false;
            for (int j = 0; j < b.size(); j++) {
                if (!mp[j] && b[j] >= f[i]) {
                    flg = true;
                    mp[j] = true;
                    break;
                } 
            }
            if (flg == false)
                cnt++;
        }
        return cnt;
    }
};