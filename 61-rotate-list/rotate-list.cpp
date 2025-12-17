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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int n = 1;
        ListNode* i = head;
        for (; i->next != NULL; i = i->next)
            n++;
        int len = n - (k % n);
        cout << len << '\n';
        if (len == n)
            return head;
        ListNode * cur = head;
        ListNode * first = NULL;
        for (int i = 1; i < len; i++)
            cur = cur->next;
        if (cur)
            first = cur->next;
        cur->next = NULL;
        i->next = head;
        head = first;
        return head;
    }
};