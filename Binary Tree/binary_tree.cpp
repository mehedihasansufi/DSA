#include <iostream>
using namespace std;
#include <queue>
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
void level_order_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cout << f->val << " ";
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
int count_node(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = count_node(root->left);
    int r = count_node(root->right);
    return l + r + 1;
}
int count_leaf_Node(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int l = count_leaf_Node(root->left);
    int r = count_leaf_Node(root->right);
    return l + r;
}
int get_max_height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL &&root->right == NULL)
    {
return 0;

    }
    int l=get_max_height(root->left);
    int r=get_max_height(root->right);
    return max(l,r)+1;
}
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *f = q.front();
            q.pop();
            int l, r;
            cin >> l >> r;
            if (l == -1)
            {
                f->left = NULL;
            }
            else
            {
                f->left = new Node(l);
                q.push(f->left);
            }
            if (r == -1)
            {
                f->right = NULL;
            }
            else
            {
                f->right = new Node(r);
                q.push(f->right);
            }
        }
    }
    return root;
}

int main()
{

    return 0;
}