class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int k = 1; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i + k == j) {
                        minHeap.push(a[i][j]);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i + k == j) {
                        a[i][j] = minHeap.top();
                        minHeap.pop();
                    }
                }
            }
        }
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    if (j + k == i) {
                        maxHeap.push(a[i][j]);
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    if (j + k == i) {
                        a[i][j] = maxHeap.top();
                        maxHeap.pop();
                    }
                }
            }
        }
        return a;
    }
};