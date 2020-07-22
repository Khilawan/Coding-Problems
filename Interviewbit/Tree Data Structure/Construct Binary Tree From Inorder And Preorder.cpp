/*

Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree.

Example :
Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3


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
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int,int>m;
    for(int i=0;i<B.size();i++){
        m[B[i]]=i;
    }
    TreeNode* root=new TreeNode(A[0]);
    for(int i=1;i<A.size();i++){
        TreeNode* node=new TreeNode(A[i]);
        TreeNode* r=root;
        int flag=0;
        while(1){
            if(m[r->val]<m[A[i]]){
                if(r->right==NULL){
                   r->right=node;
                   flag=1;
                }else{
                    r=r->right;
                }
            }else{
                if(r->left==NULL){
                   r->left=node;
                   flag=1;
                }else{
                    r=r->left;
                }
            }
            if(flag){
                break;
            }
        }
    }
    
    return root;
}
