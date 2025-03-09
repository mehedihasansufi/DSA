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
int size_node(ListNode* head){
    int sz=0;
    while(head!=NULL){
        sz++;
        head=head->next;

    }
    return sz;
}
    ListNode* middleNode(ListNode* head) {
        int size=size_node(head);
       
        if(size==1){
            return head;
        }
         else if (size % 2 == 0) { 
            int n = size / 2;
            ListNode* temp = head;
            for (int i = 1; i < n ; i++) {  
                temp = temp->next;
            }
            return temp->next;  
        } else {  
            int n = size / 2;
            ListNode* temp = head;
            for (int i = 1; i < n; i++) { 
                temp = temp->next;
            }
            return temp->next;  
        }
        
    }
};