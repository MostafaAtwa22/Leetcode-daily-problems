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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode * cur = head;
        while(cur) {
            len++;
            cur = cur->next;
        }
        int sz = len - n;
        cur = head;
        ListNode * prev = NULL;
        for (int i = 0; i < sz; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == head)
            head = head->next;
        else 
            prev->next = cur->next;
        cur->next = NULL;
        delete cur;
        return head;
    }
};