class Solution {
public:
    int conv(string s) {
        int num = 0;
        int j = 0;
        for (int i = s.size() - 1; i >= 0; i--) 
            num += pow(2, j++) * (s[i] - '0');
        return num;
    }

    string binary(int num, int max) {
        int n = num;
        string s = "";
        while (num) {
            s += (num & 1) ? '1' : '0';
            num >>= 1;
        }
        if (s.size() != max) {
            int n = max - s.size();
            for (int i = 0; i < n; i++)
                s += '0';
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string findDifferentBinaryString(vector<string>& a) {
        int n = a.size();
        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i++) {
            int num = conv(a[i]);
            mp[num] = true;
        }
        int power = a[0].size();
        int max = pow(2, power) - 1;
        int ans = 0;
        for (int i = 0; i <= max; i++) {
            if (mp[i] == false) {
                ans = i;
                break;
            }
        }
        return binary(ans, power);
    }
};