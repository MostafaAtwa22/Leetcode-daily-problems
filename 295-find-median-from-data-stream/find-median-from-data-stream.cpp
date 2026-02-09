class MedianFinder {
public:
    vector<int> v;
    MedianFinder() 
    {
    }
    void addNum(int num) {
        int i = 0;
        while (i < v.size() && (double)num > v[i])
            i++;
        v.insert(v.begin() + i, (double)num);
    }

    double findMedian() {
        if (v.size() & 1)
            return v[v.size()  / 2];
        return ((double)v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
    }
};