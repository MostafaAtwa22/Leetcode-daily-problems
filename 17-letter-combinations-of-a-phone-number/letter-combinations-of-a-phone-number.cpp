class Solution {
    vector<string> a;
    vector<string> ans;
    void BT (string s, int i, string str) {
        if (i == s.size()) {
            cout << str << '\n';
            if (str.size() == s.size())
                ans.push_back(str);
            return;
        }
        for (int j = 0; j < a[(int)(s[i] - '0') - 2].size(); ++j) {
            // do
            str += a[(int)(s[i] - '0') - 2][j];
            // recurive
            BT(s, i + 1, str);
            // undo
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string s) {
        a = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        BT(s, 0, "");
        return ans;
    }
};