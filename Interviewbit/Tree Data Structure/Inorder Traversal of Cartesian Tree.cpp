/*
Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1

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

 

TreeNode* Solution::buildTree(vector<int> &A) {
    
    if(A.size()==0){
        return NULL;
    }
    
    int i=0,n=A.size()-1;
    TreeNode* node=new TreeNode(A[i++]);
    TreeNode* root=node;
    TreeNode* prev=root;
    
    while(i<=n){
        
        TreeNode* nn=new TreeNode(A[i++]);
        
        if(root->val<nn->val){
            nn->left=root;
            root=nn;
        }else if(root->val>nn->val){
            
            prev=root;
            while(prev->right&&prev->right->val>nn->val){
                prev=prev->right;
            }
            
            if(prev->right==NULL){
                prev->right=nn;
            }else if(prev->right->val<nn->val){
                nn->left=prev->right;
                prev->right=nn;
            }
        }
    }
    return root;
}
