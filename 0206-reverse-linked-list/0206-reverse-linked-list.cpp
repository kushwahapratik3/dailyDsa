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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* ptr=head;
        ListNode* prev=NULL;
        ListNode* tem;
        while(ptr->next!=NULL){
            tem=ptr;
            ptr=ptr->next;
            tem->next=prev;
            prev=tem;
        }
        ptr->next=prev;
        head=ptr;
        return head;   
    }
};