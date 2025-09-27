double calc (double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1) * 1.0, 2) + pow((y2 - y1) * 1.0, 2)) * 1.0;
}
double Area(double l1, double l2, double l3) {
    return 0.25 * sqrt((l1 + l2 + l3) * (-l1 + l2 + l3) * (l1 - l2 + l3) * (l1 + l2 - l3));
}
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& a) {
        int n = a.size();
        double area = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double l1 = calc(a[i][0], a[i][1], a[j][0], a[j][1]);
                    double l2 = calc(a[i][0], a[i][1], a[k][0], a[k][1]);
                    double l3 = calc(a[k][0], a[k][1], a[j][0], a[j][1]);
                    area = max(area, Area(l1, l2, l3));
                }
            }
        }
        return area;
    }
};