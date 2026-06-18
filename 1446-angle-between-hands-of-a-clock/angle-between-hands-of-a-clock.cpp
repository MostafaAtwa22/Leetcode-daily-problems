class Solution {
public:
    double angleClock(int h, int m) {
        double oneMinuteDeg = 6;
        double onHDeg = 30;
        double deg1 = (h % 12) * onHDeg;
        double deg2 = 0.5 * m;
        double degM = 6 * m;
        double degH = deg1 + deg2;
        double deg = abs(degM - degH);
        return min (deg, 360 - deg);
    }
};