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
        if (head == NULL || head->next == NULL)
            return head;
        int n = 0;
        for (ListNode * i = head; i != NULL; i = i->next)
            n++;
        int sz = n - (k % n);
        if (sz <= 0)
            return head;

        ListNode* cur = head, *tail = head;
        int cntr = 1;
        while (tail->next != NULL) {
            if (cntr < sz)
                cur = cur->next;
            cntr++;
            tail = tail->next;
        }
        cout << cur->val << ' ' << tail->val << '\n';
        tail->next = head;
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};