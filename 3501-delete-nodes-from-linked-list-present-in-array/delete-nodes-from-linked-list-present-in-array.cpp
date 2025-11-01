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
    ListNode* modifiedList(vector<int>& a, ListNode* head) {
        ListNode * cur = head;
        ListNode * next = head->next;
        ListNode * prev = NULL;
        sort(a.begin(), a.end());
        while (cur) {
            bool flg = binary_search(a.begin(), a.end(), cur->val);
            if (flg) {
                if (cur == head) {
                    head = head->next;
                    cur->next = NULL;
                    cur = head;
                    next = head->next;
                    prev = NULL;
                }
                else {
                    cur->next = NULL;
                    prev->next = next;
                    cur = next;
                    if(next)
                    next = next->next;
                }
            } else {
                prev = cur;
                cur = next;
                if (next)
                next = next->next;
            }
        }
        return head;
    }
};