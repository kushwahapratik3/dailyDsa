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
        ListNode* address;
        int carry=0;
        int sum=(l1->val+l2->val+carry)%10;
        carry=(l1->val+l2->val)/10;
        ListNode* ptr= new ListNode(sum);
        ListNode* head=ptr;
        ListNode* prev=head;
        l1=l1->next;
        l2=l2->next;
        while(l1!=nullptr&&l2!=nullptr){
            sum=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            ListNode* ptr= new ListNode(sum);
            prev->next=ptr;
            prev=prev->next;
            address=ptr;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==nullptr){
            while(l2!=nullptr){
                sum=(l2->val+carry)%10;
                carry=(l2->val+carry)/10;
                ListNode* ptr= new ListNode(sum);
                prev->next=ptr;
                prev=prev->next;
                address=ptr;
                l2=l2->next;
            }
        }
        if(l2==nullptr){
            while(l1!=nullptr){
                sum=(l1->val+carry)%10;
                carry=(l1->val+carry)/10;
                ListNode* ptr= new ListNode(sum);
                prev->next=ptr;
                prev=prev->next;
                address=ptr;
                l1=l1->next;
            }
            if(carry==1){
                ListNode* ptr= new ListNode(carry);
                prev->next=ptr;
            }
        }
        return head;
    }
};