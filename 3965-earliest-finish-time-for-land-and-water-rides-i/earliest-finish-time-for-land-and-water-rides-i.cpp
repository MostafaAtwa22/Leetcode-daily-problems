class Solution {
public:
    int earliestFinishTime(vector<int>& lt, vector<int>& ld,
                           vector<int>& wt, vector<int>& wd) {

        int ans = INT_MAX;

        for (int i = 0; i < lt.size(); i++) {
            for (int j = 0; j < wt.size(); j++) {

                int landFirst =
                    max(lt[i] + ld[i], wt[j]) + wd[j];

                int waterFirst =
                    max(wt[j] + wd[j], lt[i]) + ld[i];

                ans = min({ans, landFirst, waterFirst});
            }
        }

        return ans;
    }
};