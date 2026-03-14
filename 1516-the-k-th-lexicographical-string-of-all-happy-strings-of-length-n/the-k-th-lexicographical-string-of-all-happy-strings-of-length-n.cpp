class Solution {
public:
    vector<string> a;
    
    void sol(string s, int n)
    {
        if (s.size() == n)
        {
            a.push_back(s);
            return;
        }
        for (char i = 'a'; i <= 'c'; i++)
        {
            if (!s.empty() && s.back() == i)
                continue;
            s += i;
            sol(s, n);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        sol("", n);
        if (a.size() < k)
            return "";
        return a[k - 1];
    }
};