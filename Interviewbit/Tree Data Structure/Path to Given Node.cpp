/*
Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Input Format
First Argument represents pointer to the root of binary tree A.
Second Argument is an integer B denoting the node number.

Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.

Example Input

Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output

Output 1:
 [1, 2, 5]

Output 2:
 [1]

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
bool bst(TreeNode* A, int B, vector<int>&res, vector<int>&r){
    if(A==NULL){
        return false;
    }
    res.push_back(A->val);
    if(A->val==B){
        r=res;
        return true;
    }
    if(bst(A->left,B,res,r)){
        true;
    }else if(bst(A->right,B,res,r)){
        true;
    }
    
    res.pop_back();
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>res;
    vector<int>r;
    bst(A,B,res,r);
    return r;
}
