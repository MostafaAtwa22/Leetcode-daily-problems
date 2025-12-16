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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        int n = 1;
        ListNode * cur = head, *prev = NULL, *l = NULL, *s = NULL;
        while (cur) {
            if (n + 1 == left) 
                l = cur;
            else if (n == left) {
                s = cur;
                break;
            }
            n++;
            prev = cur;
            cur = cur->next;
        }
        ListNode * next = NULL, *last = NULL;
        while (cur && n <= right) {
            if (n == right)
                last = cur;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            n++;
        }
        s->next = cur;
        if (l == NULL)
            head = last;
        else
            l->next = last;
        return head;
    }
};