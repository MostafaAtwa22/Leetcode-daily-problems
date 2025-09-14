#include <bits/stdc++.h>
using namespace std;

string toLowerStr(const string &s) {
    string res = s;
    for (char &c : res) {
        c = tolower(c);
    }
    return res;
}

string erorr(string s) {
    string str = s;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            str[i] = 'a';
        else
            str[i] = s[i];
    }
    return str;
}

class Solution {
public:
    vector<string> spellchecker(vector<string>& a, vector<string>& q) {
        unordered_map<string, bool> mp1;
        unordered_map<string, int> mp2;   
        unordered_map<string, int> mp3;  

        for (int i = 0; i < a.size(); i++) {
            mp1[a[i]] = true;
            if (!mp3.count(toLowerStr(a[i])))
                mp3[toLowerStr(a[i])] = i;
            string key = erorr(toLowerStr(a[i]));
            if (!mp2.count(key)) {  
                mp2[key] = i;
            }
        }

        int n = q.size();
        vector<string> ans(n, "");

        for (int i = 0; i < n; i++) {
            if (mp1.count(q[i])) {
                ans[i] = q[i];   
            } 
            else if (mp3.contains(toLowerStr(q[i]))) {
                ans[i] = a[mp3[toLowerStr(q[i])]];
            }
            else {
                string key = erorr(toLowerStr(q[i]));
                if (mp2.count(key)) {
                    ans[i] = a[mp2[key]];
                }
            }
        }

        return ans;
    }
};
