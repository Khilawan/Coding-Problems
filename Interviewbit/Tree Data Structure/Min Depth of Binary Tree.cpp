/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 

Example :

         1
        /
       2
       
min depth = 2.

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
    if(A->left==NULL&&A->right==NULL){
        return 1;
    }
    int l=INT_MAX,r=INT_MAX;
    if(A->left){
        l=find(A->left)+1;    
    }
    if(A->right){
        r=find(A->right)+1;    
    }
    return min(l,r);
}
 
 
int Solution::minDepth(TreeNode* A) {
    if(A==NULL){
        return 0;
    }
    int m=find(A);
    return m;
}
