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
    ListNode* Rll(ListNode* head){
        ListNode* pre=nullptr;
        ListNode* current=head;
        ListNode* post;
        while(current!=nullptr){
            post=current;
            current=current->next;
            post->next=pre;
            pre=post;
        }
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr=head;
        ListNode* ptr1=head;
        for(int i=0;i<k-1;i++){
            if(ptr1==nullptr) return head;
            ptr1=ptr1->next;
        }
        head=ptr1;
        int i;
        ListNode* rHead=new ListNode(0);
        while(ptr!=nullptr){
            ListNode* revHead=ptr;
            for(i=0;i<k-1;i++){
                ptr=ptr->next;
                if(ptr==nullptr) break;
            }
            if(i==k-1){
                rHead->next=ptr;
                ListNode* tem=ptr;
                ptr=ptr->next;
                tem->next=nullptr;
                rHead=Rll(revHead);

            }
            else {
                rHead->next=revHead;
            }
        }
        return head;

        
    }
};