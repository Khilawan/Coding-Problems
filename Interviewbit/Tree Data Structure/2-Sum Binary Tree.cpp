/*
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.

Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0

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
 unordered_set<int>s;
 
 void findans(TreeNode* A, int B, int &res){
    if(A==NULL||res){
        return;
    }
    findans(A->left,B,res);
    if(s.find(B-A->val)!=s.end()){
        res=1;
        return;
    }
    s.insert(A->val);
    findans(A->right,B,res);
 }
 
int Solution::t2Sum(TreeNode* A, int B) {
    s.clear();
    int res=0;
    findans(A,B,res);
    return res;
}
