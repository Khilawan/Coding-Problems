/*
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path has to end on a leaf node. 

Example :

         1
        /
       2
       
max depth = 2.

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
int find(TreeNode* A){
    if(A==NULL){
        return 0;
    } 
    int l=find(A->left)+1;
    int r=find(A->right)+1;
    return max(l,r);
}
 
int Solution::maxDepth(TreeNode* A) {
    if(A==NULL){
        return 0;
    }
    int mx=find(A);
    return mx;
}
