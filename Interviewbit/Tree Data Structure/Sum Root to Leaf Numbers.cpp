/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
  
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.


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
void find(TreeNode* A,int num,vector<int>&sum){
    if(A==NULL){
        return;
    } 
    num=(num*10+A->val)%1003;
    if(A->left==NULL&&A->right==NULL){
        sum.push_back(num);
        return;
    }
    find(A->left,num,sum);
    find(A->right,num,sum);
}
 
 
int Solution::sumNumbers(TreeNode* A) {
    if(A==NULL){
        return 0;
    }
    vector<int>sum;
    int num=0;
    find(A,num,sum);
    for(int i=0;i<sum.size();i++){
        num=(num+sum[i])%1003;
    }
    
    return num;
}
