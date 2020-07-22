/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return:

[
   [5,4,11,2],
   [5,8,4,5]
]


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
void preorder(TreeNode* A, int B, int sum, vector<int>&s, vector<vector<int>>&res){
    if(A==NULL){
        return;
    }
    sum+=A->val;
    s.push_back(A->val);
    if(A->left==NULL&&A->right==NULL){
        if(sum==B){
            res.push_back(s);   
        }
    }
    preorder(A->left,B,sum,s,res);
    preorder(A->right,B,sum,s,res);
    s.pop_back();
}
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>>res;
    if(A==NULL){
        return res;
    }
    vector<int>s;
    int sum=0;
    preorder(A,B,sum,s,res);
    return res;
}
