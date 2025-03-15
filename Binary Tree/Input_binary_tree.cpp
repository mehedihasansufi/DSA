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
