class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for (auto i : s) {
            if (i == 'b')
                b++;
            else if (i == 'a')
                a++;
            else if (i == 'l')
                l++;
            else if (i == 'o')
                o++;
            else if (i == 'n')
                n++;
        }
        l /= 2, o /= 2;
        return min({a, b, l, o, n});
    }
};