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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode * first = NULL;
        ListNode * second = head;
        ListNode * prev = head;
        ListNode * cur = head->next;
        while (cur) {
            while (cur && second->val == cur->val) {
                prev = cur;
                cur = cur->next;
            }
            if (prev == second) {
                first = second;
                second = prev = cur;
                cur = cur->next;
            }
            else {
                if (second == head) {
                    head = second = cur;
                    first = NULL;
                }
                else {
                    first->next = cur;
                    second = cur;
                }
                prev->next = NULL;
                prev = cur;
                if (cur)
                cur = cur->next;
            }
        }
        return head;
    }
};