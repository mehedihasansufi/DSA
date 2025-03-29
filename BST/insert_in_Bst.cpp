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

//use queue to input a tree

Node* input_tree(){
    int val;
    cin>>val;
    if(val==-1){
        return NULL;
    }
    Node* root=new Node(val);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        //queue থেকে বের করে আনা
        Node* f=q.front();
        q.pop();

        //Node নিয়ে কাজ করা 
        
        int l,r; cin>>l>>r;
        if(l==-1){
            f->left=NULL;
        }else{
            //left Node create
            f->left=new Node(l);
            //queue তে push করা
            q.push(f->left);
        }
          if(r==-1){
            f->right=NULL;
          }else{
            //right Node create
            f->right=new Node(r);
            //queue তে push করা
            q.push(f->right);

          }



    }
    return root;

}
void insert_in_BST(Node* &root,int val){
    if(root==NULL){
    //যদি কোনো value না থাকে
        root=new  Node(val);
        return;
    }
    if(root->val>val){
        //for left subtree
        if(root->left==NULL){
        //if left value is null
            root->left=new Node(val);
        }else{
       // যদি left e value থাকে
            insert_in_BST(root->left,val);
        }

    }else{
        //for right subtree
        if(root->right==NULL){
            root->right=new Node(val);
        }else{
            insert_in_BST(root->right,val);
        }
    }

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
    Node* root=input_tree();
    int val;cin>>val;
    insert_in_BST(root,val);
    level_order_traversal(root);
    
    return 0;
}
