/*
Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.


Problem Constraints
1 <= N <= 105

1 <= B <= N



Input Format
First Argument represents the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an integer array denoting the cousins of node B.

NOTE: Order doesn't matter.



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
 [6, 7]

Output 2:
 []


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
vector<int> Solution::solve(TreeNode* A, int B) {
    queue<TreeNode*>q;
    vector<int>res;
    if(A->val==B){
        return res;
    }
    
    q.push(A);
    bool found=false;
    
    while(!q.empty()&&!found){
        int qs=q.size();
        while(qs--){
            TreeNode* t=q.front();
            q.pop();
            if(t->left&&t->left->val==B){
                found=true;
            }else if(t->right&&t->right->val==B){
                found=true;
            }else{
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
        }
        if(found){
            break;
        }
    }
    while(!q.empty()){
        res.push_back(q.front()->val);
        q.pop();
    }
    
    return res;
}
