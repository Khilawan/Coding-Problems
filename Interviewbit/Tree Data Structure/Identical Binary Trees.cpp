/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True

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
 
void inorder(TreeNode* A,TreeNode* B,int &flag){
    if(A==NULL&&B==NULL){
        return;
    }else if(A==NULL&&B!=NULL||A!=NULL&&B==NULL||flag==0){
        flag=0;
        return;
    }
    if(A->val!=B->val){
        flag=0;
        return;
    }
    inorder(A->left,B->left,flag);
    inorder(A->right,B->right,flag);
}
 
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    int flag=1;
    inorder(A,B,flag);
    return flag;
}
