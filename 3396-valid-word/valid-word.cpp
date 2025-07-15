class Solution {
public:
    bool isValid(string s) {
        bool vowel = false, cons = false;
        for (auto i : s)
        {
            char c = tolower(i);
            if (!(c >= 'a' && c <= 'z') && !isdigit(i))    
                return false;
            else if (c >= 'a' && c <= 'z')
            {
                (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') ? vowel = true : cons = true;
            }
        } 
        return s.size() >= 3 && vowel && cons;
    }
};