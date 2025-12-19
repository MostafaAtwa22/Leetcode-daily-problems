/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* h = NULL;
        Node* l = NULL;
        unordered_map<Node* ,Node*> mp;
        for (Node * i = head; i != NULL; i = i->next) {
            Node * n = new Node(i->val);
            mp[i] = n;
            if (h) {
                l->next = n;
                l = n;
            }
            else {
                h = l = n;
            }
        }
        for (Node * i = head; i != NULL; i = i->next) {
            Node * copy = mp[i];
            Node * rad = i->random;
            Node* r = mp[rad];
            copy->random = r;
        }
        return h;
    }
};