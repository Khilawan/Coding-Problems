/*
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int>res;
    TreeNode* root=A;
    stack<TreeNode*>s;
    s.push(root);
    while(!s.empty()){
        TreeNode* t=s.top();
        s.pop();
        res.push_back(t->val);
        if(t->right){
            s.push(t->right);
        }
        if(t->left){
            s.push(t->left);
        }
    }
    
    return res;
}
