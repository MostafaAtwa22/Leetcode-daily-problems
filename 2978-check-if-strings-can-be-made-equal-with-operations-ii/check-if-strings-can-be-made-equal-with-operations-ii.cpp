class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string ev1 = "", od1 = "";
        string ev2 = "", od2 = "";
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                od1 += s1[i];
                od2 += s2[i];
            }
            else {
                ev1 += s1[i];
                ev2 += s2[i];
            }
        }
        sort(ev1.begin(), ev1.end());
        sort(od1.begin(), od1.end());
        sort(ev2.begin(), ev2.end());
        sort(od2.begin(), od2.end());
        return od1 == od2 && ev1 == ev2;
    }
};