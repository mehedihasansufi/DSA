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

    ListNode* deleteDuplicates(ListNode* head) {
      for(ListNode* i=head; i!=NULL; i=i->next){
        ListNode* after=i;

        for(ListNode* j=i->next; j!=NULL; ){
            if(i->val==j->val){
               ListNode* deleteNode=j;
               after->next=j->next;
               j=j->next;
               delete deleteNode;
               
            }else{
                after=j;
                j=j->next;
            }
        }
       }
       return head;
        
    }
};