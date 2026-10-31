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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ptr=head;
        if(ptr==nullptr||ptr->next==nullptr) return head;
        int count =1;
        while(ptr->next!= nullptr){
            count++;
            ptr=ptr->next;
        }
        ptr->next=head;
        ptr=ptr->next;
        k=count-(k%count);
        while(ptr!=nullptr&&k>1){
            k--;
            ptr=ptr->next;
        }
        head=ptr->next;
        ptr->next=nullptr;
        return head;
    }
};