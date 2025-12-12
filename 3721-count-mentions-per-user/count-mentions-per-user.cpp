class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& a) {
        vector<vector<pair<int, int>>> f(n);
        vector<int> ans(n, 0);
        int m = a.size();
        for (int i = 0; i < m; i++)
        {
            if (a[i][0] == "OFFLINE")
            {
                int id = stoi(a[i][2]);
                int from = stoi(a[i][1]);
                int to = from + 59;
                f[id].push_back({from, to});
            }
        }
        for (int i = 0; i < m; i++)
        {

            if (a[i][0] == "MESSAGE") 
            {
                string mention = a[i][2];
                int time = stoi(a[i][1]);

                if (mention == "ALL")
                {
                    for(int j = 0; j < n; j++)
                        ans[j]++;
                }
                else if (mention == "HERE")
                {
                    for (int j = 0; j < n; j++)
                    {
                        bool flg = true;
                        for (auto k : f[j]) 
                        {
                            if (k.first <= time && k.second >= time)
                            {
                                flg = false;
                                break;
                            }
                        }
                        if (flg)
                            ans[j]++;
                    }
                }
                else
                {
                    string str = "";
                    for (auto j : mention) 
                    {
                        if (j == ' ')
                        {
                            int id = stoi(str.substr(2));
                            ans[id]++;
                            str = "";
                        }
                        else
                            str += j;
                    }
                    int id = stoi(str.substr(2));
                    ans[id]++;
                }
            }
        }
        return ans;
    }
};