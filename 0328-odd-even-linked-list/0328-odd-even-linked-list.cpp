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
        ListNode* ptr =head;
        ListNode* dummy1=new ListNode(0);
        ListNode* pre1=dummy1;
        ListNode* dummy2=new ListNode(0);
        ListNode* pre2=dummy2;
        while(ptr!=nullptr){
            ListNode* node1=new ListNode(ptr->val);
            pre1->next=node1;
            pre1=node1;
            if(ptr->next!=nullptr){
                ptr=ptr->next;
                ListNode* node2=new ListNode(ptr->val);
                pre2->next=node2;  
                pre2=node2;
            }
            ptr=ptr->next;
        }
        pre1->next=dummy2->next;
        return dummy1->next;
        
    }
};