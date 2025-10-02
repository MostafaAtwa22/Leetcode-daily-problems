class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == '_')
                i++;
            while (j < n && target[j] == '_')
                j++;
            if (start[i] != target[j])
                return false;
            else if (start[i] == 'L' && j > i)
                return false;
            else if (start[i] == 'R' && j < i)
                return false;
            cout << i << ' ' << j << '\n';
            i++, j++;
        }
        while (i < n && start[i] == '_')
            i++;
        while (j < n && target[j] == '_')
            j++;
        return i == j;
    }
};