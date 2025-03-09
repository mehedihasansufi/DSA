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
void printing(ListNode* head, vector<int>&v){
    ListNode* temp=head;
    while(temp!=NULL){
       v.push_back(temp->val);
        temp=temp->next;
    }
   
}
void recursion(ListNode* head,vector<int>&v){
  
    if(head==NULL){
        return ;
    }
   
    recursion(head->next,v);
   v.push_back(head->val);
}

    bool isPalindrome(ListNode* head) {
        vector<int>forward;
        vector<int>backward;
        ListNode* temp=head;
        printing(head,forward);
        recursion(head,backward);


        int V_size=forward.size();
    int V2_size=backward.size();
    if(forward!=backward){
        return false;
    }else{
        for(int i=0; i<forward.size(); i++){
          if(forward[i]!=backward[i]){
            return false;
          }
        }
        return true;
    }
    }
};