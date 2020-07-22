/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

Example :

Given A : [1, 2, 3]

A height balanced BST  : 

      2
    /   \
   1     3

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
TreeNode* AVL(const vector<int> &A,int l,int r){
    if(l==r){
        TreeNode* node=new TreeNode(A[l]);
        return node;
    }else if(l>r){
        return NULL;
    }
    
    int mid=(l+r)/2;
    TreeNode* node=new TreeNode(A[mid]);
    node->left=AVL(A,l,mid-1);
    node->right=AVL(A,mid+1,r);
    return node;
}
 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n=A.size();
    int mid=n/2;
    TreeNode* root;
    root=AVL(A,0,n-1);
    return root;
}
