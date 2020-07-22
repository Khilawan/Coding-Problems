/*
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST  

*/


void inorder(TreeNode* A,vector<int>&res){
    if(A==NULL){
        return;
    }
    
    inorder(A->left,res);
    res.push_back(A->val);
    inorder(A->right,res);
}
 
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int>v;
    inorder(A,v);
    vector<int>b=v;
    sort(b.begin(),b.end());
    vector<int>res(2);
    for(int i=0;i<b.size();i++){
        if(v[i]!=b[i]){
            res[0]=v[i]<b[i]?v[i]:b[i];
            res[1]=v[i]>b[i]?v[i]:b[i];
            break;
        }
    }
    return res;
}
