class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char ind = '0';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '9')
            {
                ind = s[i];
                break;
            }
        }
        string s1 = s, s2 = s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s1[i] == ind)
                s1[i] = '9';
            if (s2[i] == s[0])
                s2[i] = '0';
        }
        cout << s1 << ' ' << s2 << '\n';
        return stoi(s1) - stoi(s2);
    }
};