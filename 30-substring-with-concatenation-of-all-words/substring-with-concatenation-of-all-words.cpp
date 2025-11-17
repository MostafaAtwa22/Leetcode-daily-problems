class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        int w = words[0].size();
        int total = w * words.size();

        if (n < total) return ans;

        unordered_map<string,int> target;
        for (auto &word: words) target[word]++;

        for (int offset = 0; offset < w; offset++) {
            int left = offset, count = 0;
            unordered_map<string,int> window;

            for (int right = offset; right + w <= n; right += w) {
                string word = s.substr(right, w);

                if (target.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > target[word]) {
                        string leftWord = s.substr(left, w);
                        window[leftWord]--;
                        left += w;
                        count--;
                    }

                    if (count == words.size()) {
                        ans.push_back(left);
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + w;
                }
            }
        }

        return ans;
    }
};
