void level_order_traversal(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* f=q.front();
        q.pop();
        cout<<f->val<<" ";
        if(f->left!=NULL){
            q.push(f->left);
        }
        if(f->right!=NULL){
            q.push(f->right);
        }

    }
}
