#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* converting_array_to_BST(int arr[],int n,int l,int r){

    if(l>r){
        return NULL;
    }
    int mid=(l+r)/2;
    Node* root=new  Node(arr[mid]);
    Node* leftsubtree=converting_array_to_BST(arr,n,l,mid-1);
    Node* rightsubtree=converting_array_to_BST(arr,n,mid+1,r);
    root->left=leftsubtree;
    root->right=rightsubtree;
    return root;


}

//use queue for level order traversal

void level_order_traversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
          // 1 queue থেকে বের করে আনা
        Node* f=q.front();
        q.pop();

         // 2 Node নিয়ে কাজ করা 
         cout<<f->val<<" ";

         // 3 queue তে push করা

         if(f->left)
           q.push(f->left);
           if(f->right)
              q.push(f->right);

    }

}

int main() {

   int n;
   cin>>n;
   int arr[n];
   for(int i=0; i<n; i++){
    cin>>arr[i];
   }
   Node* root=converting_array_to_BST(arr,n,0,n-1);
    level_order_traversal(root);
    
    return 0;
}