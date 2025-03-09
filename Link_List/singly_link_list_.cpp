#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_head(Node *&head, Node *&tail, int val)//o(1)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void insert_any_pos(Node *head, int idx, int val)//o(n)
{
    Node *newnode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void insert_at_tail(Node *&head, Node *&tail, int val)//o(1)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
void delete_at_head(Node *&head, Node *&tail)//o(1)
{
    if (head == NULL)
    {
        return;
    }
    Node *deleteNode = head;
    if (head->next == NULL)
    {
        tail = NULL;
    }
    head = head->next;
    delete deleteNode;
}
void delete_any_pos(Node *head, int idx)//o(n)
{
    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}
void delete_at_tail(Node* &head, Node* &tail)// o(n)
{
    if(head==NULL){
        return;
    }
    if(tail->next==NULL){
        delete tail;
        tail=NULL;
        head=NULL;
        return;
    }
    Node* temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    delete tail;
    tail=temp;
    tail->next=NULL;    
}
void print(Node *head)//o(n)
{
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
}
void print_recurison(Node *head)//o(n)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->val << endl;
    print_recurison(head->next);
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    print(head);
    return 0;
}