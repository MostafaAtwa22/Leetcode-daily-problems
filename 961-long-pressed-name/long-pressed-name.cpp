class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < name.size() && i < typed.size()) {
            if (j && typed[i] != typed[i - 1] && name[j] != typed[i])
                return false;
            if (name[j] == typed[i])
                j++;
            i++;
        }
        for (int k = i; k < typed.size(); k++) {
            if (typed[k] != typed[i - 1])
                return false;
        }
        return j == name.size() && name[0] == typed[0];
    }
};