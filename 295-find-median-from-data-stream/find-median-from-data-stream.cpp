class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    int n = 0;
    MedianFinder() 
    {
    }
    void addNum(int num) {
        n++;
        small.push(num);
        if (small.size() - large.size() > 1) {
            large.push(small.top());
            small.pop();
        }
        if (!large.empty() && small.top() > large.top()) {
            int l = large.top();
            int s = small.top();
            large.pop();
            small.pop();
            large.push(s);
            small.push(l);
        }
    }

    double findMedian() {
        if (n & 1)
            return small.top();
        return (small.top() + large.top()) / 2.0;
    }
};