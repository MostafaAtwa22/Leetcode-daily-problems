class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> f (55, 0);
        vector<int> C(n);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            f[A[i]]++;
            f[B[i]]++;
            for (int j = 0; j < 55; j++) {
                if (f[j] == 2)
                    cnt++;
            }
            C[i] = cnt;
        }
        return C;
    }
};