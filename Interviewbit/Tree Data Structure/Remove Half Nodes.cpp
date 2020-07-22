/*
Given a binary tree A with N nodes.

You have to remove all the half nodes and return the final binary tree.

NOTE:

Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.


Problem Constraints
1 <= N <= 105



Input Format
First and only argument is an pointer to the root of binary tree A.



Output Format
Return a pointer to the root of the new binary tree.



Example Input

Input 1:

           1
         /   \
        2     3
       / 
      4

Input 2:

            1
          /   \
         2     3
        / \     \
       4   5     6


Example Output

Output 1:

           1
         /    \
        4      3
        
Output 2:

            1
          /   \
         2     6
        / \

       4   5


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
 
 void find(TreeNode* A){
     
    if(A==NULL||A->left==NULL&&A->right==NULL){
        return;
    }
    if(A->left==NULL&&A->right!=NULL){
        A->val=A->right->val;
        TreeNode* rr=A->right->right;
        TreeNode* rl=A->right->left;
        A->right=rr;
        A->left=rl;
        find(A);
    }else if(A->left!=NULL&&A->right==NULL){
        A->val=A->left->val;
        TreeNode* ll=A->left->left;
        TreeNode* lr=A->left->right;
        A->left=ll;
        A->right=lr;
        find(A);
    }else{
        find(A->left);
        find(A->right);    
    }
    
 }
 
TreeNode* Solution::solve(TreeNode* A) {
    if(A->left==NULL&&A->right==NULL){
        return A;
    }
    find(A);
    return A;
}
