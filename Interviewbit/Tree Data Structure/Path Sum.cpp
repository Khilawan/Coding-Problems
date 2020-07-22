/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

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
void preorder(TreeNode* A, int B, int &flag,int sum){
    if(A==NULL||flag){
        return;
    } 
    sum+=A->val;
    if(A->left==NULL&&A->right==NULL){
        if(sum==B){
            flag=1;
            return;
        }
    }
    preorder(A->left,B,flag,sum);
    preorder(A->right,B,flag,sum);
}
 
int Solution::hasPathSum(TreeNode* A, int B) {
    int flag=0;
    int sum=0;
    preorder(A,B,flag,sum);
    return flag;
}
