/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int>ans;
        bool freq[200]={false};
        queue<pair<TreeNode*, int>>q;
        if(root)
          q.push({root,1});
          while(!q.empty()){
            TreeNode* f=q.front().first;
            int level=q.front().second;
            q.pop();

            //node nia kaj kora
            if(freq[level]==false){
                ans.push_back(f->val);
                freq[level]=true;
            }


            //children push kora queue ta
            if(f->right)
                   q.push({f->right,level+1});
            if(f->left)
                q.push({f->left,level+1});
                

          }
          return ans;
        
    }
};