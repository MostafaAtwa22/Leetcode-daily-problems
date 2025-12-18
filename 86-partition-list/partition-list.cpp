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
    ListNode* partition(ListNode* head, int x) {
        ListNode * h1 = NULL, *l1 = NULL, *h2 = NULL, *l2 = NULL;
        for (ListNode * i = head; i != NULL; i = i->next) {
            ListNode * n = new ListNode(i->val);
            if (i->val < x) {
                if (h1 == NULL)
                    h1 = l1 = n;
                else {
                    l1->next = n;
                    l1 = n;
                }
            }
            else {
                if (h2 == NULL)
                    h2 = l2 = n;
                else {
                    l2->next = n;
                    l2 = n;
                }
            }
        }
        if (l1)
            l1->next = h2;
        return h1 ? h1 : h2;
    }
};