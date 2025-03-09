#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node* prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev=NULL;
    }
};
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newnode=new  Node(val);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;


}
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}
void insert_any_pos(Node* head, int idx, int val){
    Node* newnode=new Node(val);
    Node* temp=head;
    for(int i=1; i<idx; i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
}
void delete_at_head(Node* &head,Node * &tail){
   if(head==NULL){
    return;
   }
   Node* deleteNode=head;
   head=head->next;
   delete deleteNode;
   if(head==NULL){
    tail=NULL;
    return;
   }
   head->prev=NULL;
   
    
}
void delete_at_tail(Node* &head,Node* &tail){
   
    if(head==NULL){
      
        return;
    }
    Node* deleteNode=tail;
    tail=tail->prev;
    delete deleteNode;
    if(tail==NULL){
        head=NULL;
        return;
    }
    tail->next=NULL;

}
void delete_any_pos(Node* head,int idx){
    Node* temp=head;
    for(int i=1; i<idx; i++){
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete deleteNode;

}
void print(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
void backword_print(Node* tail){
    while(tail!=NULL){
        cout<<tail->val<<" ";
        tail=tail->prev;
    }
}
int main (){
    Node* head=NULL;
    Node* tail=NULL;
    while(true){
        int val;
        cin>>val;
        if(val==-1)
        break;
        insert_at_tail(head,tail,val);

    }
   
    print(head);
    delete_any_pos(head,2);
    //backword_print(tail);
    print(head);
   
    return 0;
}