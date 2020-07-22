/*
Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    vector<int>res;
    TreeNode* root=A;
    stack<TreeNode*>s;
    s.push(root);
    
    while(!s.empty()){
        TreeNode* t=s.top();
        s.pop();
        res.push_back(t->val);
        if(t->left){
            s.push(t->left);
        }
        if(t->right){
            s.push(t->right);
        }
    }
    
    reverse(res.begin(),res.end());
    
    return res;
}
