/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
*/

void find(vector<vector<int> >&res,vector<int>&A,int l,int r){
    if(l==r){
        res.push_back(A);
    }else{
        for(int i=l;i<=r;i++){
            swap(A[l],A[i]);
            find(res,A,l+1,r);
            swap(A[l],A[i]);
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>>res;
    find(res,A,0,A.size()-1);
    return res;
}
