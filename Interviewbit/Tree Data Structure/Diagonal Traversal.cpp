/*
Consider lines of slope -1 passing between nodes.

Given a Binary Tree A containing N nodes, return all diagonal elements in a binary tree belonging to same line.

NOTE:

See Sample Explanation for better understanding.
Order does matter in the output.
To get the same order as in the output traverse the tree same as we do in pre-order traversal.


Example Input

Input 1:

            1
          /   \
         4      2
        / \      \
       8   5      3
          / \    /
         9   7  6

Input 2:

             11
          /     \
         20      12
        / \       \
       1   15      13
          /  \     /
         2    17  16
          \   /
          22 34


Example Output

Output 1:
 [1, 2, 3, 4, 5, 7, 6, 8, 9]

Output 2:
 [11, 12, 13, 20, 15, 17, 16, 1, 2, 22, 34]


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
void inorder(TreeNode* A,map<int,vector<int>>&m,int set){
    if(A==NULL){
        return;
    } 
    inorder(A->left,m,set+1);
    m[set].push_back(A->val);
    inorder(A->right,m,set);
}
 
vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int>>m;
    vector<int>res;
    inorder(A,m,0);   
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            res.push_back(m[i][j]);
        }
    }
    return res;
}
