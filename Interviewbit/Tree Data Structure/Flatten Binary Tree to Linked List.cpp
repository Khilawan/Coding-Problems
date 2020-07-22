/*
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6

     
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.


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
TreeNode* pre(TreeNode* A){
    if(A==NULL){
        return NULL;
    }
    TreeNode* r=A->right;    
    A->right=pre(A->left);
    TreeNode* h=A;
    while(h->right){
        h->left=NULL;
        h=h->right;
    }
    h->right=pre(r);
    
    return A;
}
 
 
TreeNode* Solution::flatten(TreeNode* A) {
    if(A==NULL){
        return NULL;
    }
    if(A->left==NULL&&A->right==NULL){
        return A;
    }
    TreeNode* root=pre(A);
    
    return root;
}
