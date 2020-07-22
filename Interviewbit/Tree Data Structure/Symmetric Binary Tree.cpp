/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3

The above binary tree is symmetric.
But the following is not:

    1
   / \
  2   2
   \   \
   3    3

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
    inorder(A->left,B->right,flag);
    inorder(A->right,B->left,flag);
}
 
 
int Solution::isSymmetric(TreeNode* A) {
    if(A==NULL||A->left==NULL&&A->right==NULL){
        return 1;
    }
    int flag=1;
    inorder(A->left,A->right,flag);
    return flag;
}
