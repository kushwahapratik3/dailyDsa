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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ptr= head;
        if(head==nullptr) return head;
        ListNode* odd=ptr;
        ListNode* pre1=odd;
        ListNode* even;
        ListNode* pre2;
        if(ptr->next!=nullptr){
            ptr=ptr->next;
            even=ptr;
            pre2=even;
        }
        ptr=ptr->next;
        while(ptr!=nullptr){
            pre1->next=ptr;
            pre1=ptr;
            ptr=ptr->next;
            pre2->next=ptr;
            pre2=ptr;
            if(ptr!=nullptr) ptr=ptr->next;
        }
        pre1->next=even;
        return head;
        
    }
};