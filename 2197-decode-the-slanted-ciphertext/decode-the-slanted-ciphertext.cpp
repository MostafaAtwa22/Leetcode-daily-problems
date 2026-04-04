class Solution {
public:
    string decodeCiphertext(string s, int r) {
        if (r == 0) return "";
        
        int n = s.size();
        int col = n / r;
        
        vector<vector<char>> a(r, vector<char>(col));
        
        int k = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < col; j++) {
                a[i][j] = s[k++];
            }
        }

        string str = "";

        for (int startCol = 0; startCol < col; startCol++) {
            int i = 0, j = startCol;
            while (i < r && j < col) {
                str += a[i][j];
                i++;
                j++;
            }
        }

        while (!str.empty() && str.back() == ' ')
            str.pop_back();

        return str;
    }
};