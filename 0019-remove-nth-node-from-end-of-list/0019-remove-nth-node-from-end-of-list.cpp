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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* ptr=head;
        while(ptr!=nullptr){
            count++;
            ptr=ptr->next;
        }
        if(n==count) return head->next;
        int N=count-n;
        ListNode* dummy=head;
        for(int i=0;i<N-1;i++){
            dummy=dummy->next;
        }
        dummy->next=dummy->next->next;
        return head;
        
    }
};