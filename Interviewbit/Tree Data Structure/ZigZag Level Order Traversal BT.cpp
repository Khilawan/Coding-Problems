/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
   
return

[
         [3],
         [20, 9],
         [15, 7]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    if(A==NULL){
        return {};
    }
    queue<TreeNode*>q;
    q.push(A);
    
    int num=0;
    vector<vector<int> >res;
    vector<int>v;
    
    while(!q.empty()){
        
        v.clear();
        int size=q.size();
        
        while(size--){
            TreeNode* t=q.front();
            q.pop();
            v.push_back(t->val);
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
        
        if(num==1){
            reverse(v.begin(),v.end());
        }
        
        num=(num+1)%2;
        res.push_back(v);
    }
    
    return res;
}
