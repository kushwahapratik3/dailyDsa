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
    ListNode* reverseLL(ListNode* head){
        ListNode* pre=nullptr;
        ListNode* current=head;
        ListNode* post;
        while(current!=nullptr){
            post=current;
            current=current->next;
            post->next=pre;
            pre=post;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=reverseLL(slow);
        ListNode* first=head;
        while(second!=nullptr){
            if(first->val!=second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;  
    }
};