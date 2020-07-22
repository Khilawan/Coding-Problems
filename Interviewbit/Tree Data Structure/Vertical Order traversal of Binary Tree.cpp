/*
Given a binary tree A consisting of N nodes, return a 2-D array denoting the vertical order traversal of A.

Go through the example and image for more details.

NOTE:

If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the level-order traversal of tree comes first in the output.
Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be the nodes on the rightmost vertical line.

Example Input

Input 1:

      6
    /   \
   3     7
  / \     \
 2   5     9

Input 2:

           1
         /   \
        2     3
       / \
      4   5


Example Output

Output 1:

 [
    [2],
    [3],
    [6, 5],
    [7],
    [9]
 ]
 
Output 2:

 [
    [4],
    [2],
    [1, 5],
    [3]
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
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    
    map<int,vector<int>>m;
    vector<vector<int>>res;
    if (!A) 
        return res;
    
    queue<pair<TreeNode*,int>>q;
    q.push(make_pair(A,0));
    
    while(!q.empty()){
        pair<TreeNode*,int> t;
        t=q.front();
        q.pop();
        
        if(t.first->left!=NULL){
            q.push(make_pair(t.first->left,t.second-1));
        }
        if(t.first->right!=NULL){
            q.push(make_pair(t.first->right,t.second+1));
        }
        
        m[t.second].push_back(t.first->val);
    }
    
    for(auto it=m.begin();it!=m.end();it++){
        res.push_back(it->second);
    }
    return res;
}
