/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>address;
        while(address.find(head)==address.end()){
            if(head==NULL) return false;
            address.insert(head);
            head=head->next;
        }
        return true;
    }
};