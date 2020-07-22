/*
Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 

Example :
Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

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
    for(int i=0;i<A.size();i++){
        m[A[i]]=i;
    }
    int n=B.size()-1;
    TreeNode* root=new TreeNode(B[n]);
    for(int i=n-1;i>=0;i--){
        TreeNode* r=root;
        TreeNode* node=new TreeNode(B[i]);
        int flag=0;
        while(1){
            if(m[r->val]<m[B[i]]){
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
