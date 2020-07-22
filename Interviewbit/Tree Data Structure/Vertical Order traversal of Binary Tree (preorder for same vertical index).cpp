/*
Given a binary tree A consisting of N nodes, return a 2-D array denoting the vertical order traversal of A.

Go through the example and image for more details.

NOTE:

If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the pre-order traversal of tree comes first in the output.
Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be the nodes on the rightmost vertical line.

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
void preorder(TreeNode* A,map<int,vector<int>>&m,int n,int &mn,int &mx){
    if(A==NULL){
        return;
    }
    m[n].push_back(A->val);
    if(n<mn){
        mn=n;
    }else if(n>mx){
        mx=n;
    }
    preorder(A->left,m,n+1,mn,mx);
    preorder(A->right,m,n-1,mn,mx);
}
 
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int,vector<int>>m;
    vector<vector<int>>res;
    int mn=0;
    int mx=0;
    preorder(A,m,0,mn,mx);
    //cout<<m.size()<<endl;
    //cout<<mn<<" "<<mx<<endl;
    for(int i=mx;i>=mn;i--){
        res.push_back(m[i]);
    }
    
    return res;
}
