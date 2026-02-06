class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int len = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string cur = q.front();
                q.pop();

                if (cur == endWord)
                    return len;

                for (int i = 0; i < cur.size(); i++) {
                    char old = cur[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == old) continue;
                        cur[i] = ch;

                        if (st.count(cur)) {
                            q.push(cur);
                            st.erase(cur); 
                        }
                    }
                    cur[i] = old;
                }
            }
            len++;
        }
        return 0;
    }
};
