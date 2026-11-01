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
private: 
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        while(list1!=nullptr&&list2!=nullptr){
            if(list1->val<=list2->val){
                dummy->next=list1;
                dummy=dummy->next;
                list1=list1->next;
            }
            else{
                dummy->next=list2;
                dummy=dummy->next;
                list2=list2->next;
            }
        }
        if(list1==nullptr) dummy->next=list2;
        if(list2==nullptr) dummy->next=list1;
        return head->next;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
   
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* middle=findMiddle(head);
        ListNode* leftHead=head;
        ListNode* rightHead=middle->next;
        middle->next=nullptr;
        ListNode* ptr1=sortList(leftHead);
        ListNode* ptr2=sortList(rightHead);
        return merge(ptr1,ptr2);
    }

};