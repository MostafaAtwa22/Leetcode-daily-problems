bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> f(26, 0);
        int maxV = 0, maxC = 0;
        for (auto i : s) {
            f[i - 'a']++;
            if (isVowel(i))
                maxV = max(f[i - 'a'], maxV);
            else 
                maxC = max(f[i - 'a'], maxC);
        }
        return maxV + maxC;
    }
};