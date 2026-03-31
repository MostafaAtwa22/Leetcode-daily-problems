class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<bool> freq(n + m - 1, false);
        string str(n + m - 1, 'a');
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'T') {
                if (freq[i] && str.substr(i, m) != s2) {
                    int k = 0;
                    for (int j = i; j < i + m; j++) {
                        if (freq[j]) {
                            if (str[j] != s2[k])
                                return "";
                        }
                        else {
                            freq[j] = true;
                            str[j] = s2[k];
                        }
                        k++;
                    }
                }  
                else if (!freq[i]) {
                    int k = 0;
                    for (int j = i; j < i + m; j++) {
                        str[j] = s2[k++];
                        freq[j] = true;
                    }
                }
            }
        }
        cout << str << '\n';
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'F') {
                if (str.substr(i, m) != s2) 
                    continue;
                else {
                    bool flg = false;
                    for (int j = m + i - 1; j >= i; j--) {
                        if (!freq[j]) {
                            str[j] = str[j] + 1;  
                            flg = true;
                            break;
                        }
                    }
                    if (!flg)
                        return "";
                }
            }
        }
        cout << str << '\n';
        return str;
    }
};