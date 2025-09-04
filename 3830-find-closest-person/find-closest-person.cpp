class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dx = abs(z - x);
        int dy = abs(z - y);
        if (dx > dy)
            return 2;
        else if (dx < dy)
            return 1;
        return 0;
    }
};