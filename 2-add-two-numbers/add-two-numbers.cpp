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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem = 0;
        ListNode* head = NULL;
        ListNode* last = NULL;
        while (l1 && l2) {
            int sum = l1->val + l2->val + rem;
            int val;
            if (sum >= 10) {
                rem = sum / 10;
                val = sum % 10;
            }
            else {
                rem = 0;
                val = sum;
            }
            ListNode * n = new ListNode(val);
            if  (!head)
                head = last = n;
            else {
                last->next = n;
                last = n;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int sum = l1->val + rem;
            int val;
            if (sum >= 10) {
                rem = sum / 10;
                val = sum % 10;
            }
            else {
                rem = 0;
                val = sum;
            }
            ListNode * n = new ListNode(val);
            last->next = n;
            last = n;
            l1 = l1->next;
        }
        while (l2) {
            int sum = l2->val + rem;
            int val;
            if (sum >= 10) {
                rem = sum / 10;
                val = sum % 10;
            }
            else {
                rem = 0;
                val = sum;
            }
            ListNode * n = new ListNode(val);
            last->next = n;
            last = n;
            l2 = l2->next;
        }
        if (rem) {
            ListNode * n = new ListNode(rem);
            last->next = n;
        }
        return head;
    }
};