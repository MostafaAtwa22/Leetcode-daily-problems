struct Compare 
{
    bool operator()(const std::pair<char, int>& a, const std::pair<char, int>& b) 
    {
        if (a.first == b.first) 
            return a.second < b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                pq.pop();
            }
            else
                pq.push({s[i], i});
        }
        vector<pair<int, char>> a(pq.size());
        int j = 0;
        while (!pq.empty())
        {
            a[j++] = {pq.top().second, pq.top().first};
            
            pq.pop();
        }
        sort(a.begin(), a.end());
        string ans;
        for (int i = 0; i < a.size(); i++)
        {
            ans += a[i].second;
        }
        return ans;
    }
};