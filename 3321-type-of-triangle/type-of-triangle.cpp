class Solution {
public:
    string triangleType(vector<int>& a) {
        if ((a[0] + a[1] <= a[2]) || (a[2] + a[1] <= a[0]) || (a[0] + a[2] <= a[1]))
            return "none";
        if (a[0] == a[1] && a[1] == a[2])
            return "equilateral";
        else if ((a[0] == a[1] && a[0] != a[2])
        || (a[0] == a[2] && a[0] != a[1])
        || (a[2] == a[1] && a[0] != a[2]))
            return "isosceles";
        else if (a[0] != a[1] && a[1] != a[2] && a[0] != a[2])
            return "scalene";
        return "none";
    }
};