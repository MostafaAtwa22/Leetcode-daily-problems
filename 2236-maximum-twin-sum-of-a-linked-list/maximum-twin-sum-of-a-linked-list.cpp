/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode * cur = head;
        vector<int> a;
        while(cur) {
            a.push_back(cur->val);
            cur = cur->next;
        }

        int n = a.size();
        int r = n / 2;
        int l = r - 1;
        int ans = INT_MIN;
        while (l >= 0 && r < n) {
            ans = max(ans, a[l--] + a[r++]);
        }
        return ans;
    }
};