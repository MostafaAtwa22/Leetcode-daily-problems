class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string> a;
        for (int i = 0; i < 31; i++) {
            int x = (1 << i);
            string s = to_string(x);
            sort(s.begin(), s.end());
            a.insert(s);
        }
        for (auto i : a)
            cout << i << '\n';
        string str = to_string(n);
        sort(str.begin(), str.end());
        return a.find(str) != a.end();
    }
};