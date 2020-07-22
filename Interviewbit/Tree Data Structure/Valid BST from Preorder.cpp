/*
You are given a preorder traversal A, of a Binary Search Tree.

Find if it is a valid preorder traversal of a BST.



Problem Constraints
1 <= A[i] <= 106

1 <= |A| <= 105



Input Format
First and only argument is an integer array A denoting the pre-order traversal.



Output Format

Return an integer:
0 : Impossible preorder traversal of a BST
1 : Possible preorder traversal of a BST


Example Input

Input 1:
A = [7, 7, 10, 10, 9, 5, 2, 8]


Example Output

Output 1:
 1

*/


int Solution::solve(vector<int> &A) {
    int n=A.size();
    if(n==0||n==1){
        return 1;
    }
    vector<int>l;
    vector<int>r;
    int i=1;
    int root=A[0];
    while(i<n&&A[i]<=root){
        l.push_back(A[i++]);
    }
    while(i<n&&A[i]>root){
        r.push_back(A[i++]);
    }
    if(i!=n){
        return 0;
    }
    int ls=solve(l);
    int rs=solve(r);
    return ls&&rs;
}
