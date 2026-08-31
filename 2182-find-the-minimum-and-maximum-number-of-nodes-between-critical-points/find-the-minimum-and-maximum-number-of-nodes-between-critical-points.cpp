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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> a(2, -1);
        if (!head || !head->next)
            return a;

        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* next = cur->next;
        int ind = 2;
        vector<int> arr;
        while (cur && next) {
            if ((cur->val > prev->val && cur->val > next->val)
            || (cur->val < prev->val && cur->val < next->val))
                arr.push_back(ind);
            ind++;
            prev = cur;
            cur = next;
            next = next->next;
        }

        if (arr.size() < 2) 
            return a;
        
        a[0] = INT_MAX;
        a[1] = arr[arr.size() - 1] - arr[0];

        for (int i = 1; i < arr.size(); i++)
            a[0] = min(a[0], arr[i] - arr[i - 1]);
        return a;
    }
};