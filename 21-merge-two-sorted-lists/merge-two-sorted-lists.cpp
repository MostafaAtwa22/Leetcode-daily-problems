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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * head = NULL, *last = NULL;
        ListNode * l1 = list1, *l2 = list2;
        while (l1 && l2) {
            if (l1->val >= l2->val) {
                if (head == NULL) 
                    head = last = l2;
                else {
                    last->next = l2;
                    last = l2;
                }
                l2 = l2->next;
            }
            else {
                if (head == NULL) 
                    head = last = l1;
                else {
                    last->next = l1;
                    last = l1;
                }
                l1 = l1->next;
            }
        }

        if (l1) {
            if (last)
                last->next = l1;
            else 
                head = l1;
        }
        else if (l2) {
            if (last)
                last->next = l2;
            else
                head = l2;
        }
        return head;
    }
};