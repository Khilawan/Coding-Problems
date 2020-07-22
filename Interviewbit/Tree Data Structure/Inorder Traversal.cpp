/*
Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.

*/

/*/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int>res;
    stack<TreeNode*>s;
    TreeNode* root=A;
    
    while(!s.empty()||root){
        if(root){
            s.push(root);
            root=root->left;
        }else{
            TreeNode* tmp=s.top();
            s.pop();
            res.push_back(tmp->val);
            root=tmp->right;
        }
    }
    return res;
}
