class Solution {
public:
    int compress(vector<char>& a) {
        int n = a.size();
        int idx = 0; // write index

        for (int i = 0; i < n; ) {
            char c = a[i];
            int j = i;
            while (j < n && a[j] == c) j++; // count duplicates

            a[idx++] = c; // write the character

            int count = j - i;
            if (count > 1) {
                string s = to_string(count);
                for (char ch : s)
                    a[idx++] = ch; 
            }
            i = j;
        }
        return idx;
    }
};
