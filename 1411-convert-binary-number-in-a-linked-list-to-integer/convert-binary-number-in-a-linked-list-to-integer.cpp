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
    int getDecimalValue(ListNode* head) {
        int n = 0;
        int j = 0;
        ListNode * prev = NULL;
        ListNode * cur = head;
        ListNode * next = head->next;
        while (cur) 
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            if (next)
                next = next->next;
        }
        head = prev;
        for (ListNode * i = head; i != NULL; i = i->next)
        {
            n += pow(2, j) * i->val;
            j++;
        }
        return n;
    }
};