/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.

 NOTE : You may assume 1 <= k <= Total number of nodes in BST 

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
 void findkth(TreeNode* A, int B,vector<int>&res){
    if(A==NULL||res.size()==B){
        return;
    }
    findkth(A->left,B,res);
    res.push_back(A->val);
    if(res.size()==B){
        return;
    }
    findkth(A->right,B,res);
 }
 
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int>res;
    findkth(A,B,res);
    return res[B-1];
}
