/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.


Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/


void find(vector<int> &A,vector<int> &v,vector<vector<int>> &res,int s,int n){
    
    res.push_back(v);
    for(int i=s;i<n;i++){
        v.push_back(A[i]);
        find(A,v,res,i+1,n);
        v.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>>res;
    vector<int>v;
    int n=A.size();
    sort(A.begin(),A.end());
    find(A,v,res,0,n);
    return res;
}
