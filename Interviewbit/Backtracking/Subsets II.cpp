/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.

Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

*/


void find(vector<int>&A,set<vector<int>>&ans,vector<vector<int>>&res,vector<int>&v,int i,int n){
    if(i>n){
        return;
    }
    if(i==n){
        ans.insert(v);
        return;
    }
    ans.insert(v);
    v.push_back(A[i]);
    find(A,ans,res,v,i+1,n);
    v.pop_back();
    while(i<n&&A[i]==A[i+1])i++;
    find(A,ans,res,v,i+1,n);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    set<vector<int>>ans;
    vector<vector<int>>res;
    vector<int>v;
    int i=0;
    int n=A.size();
    sort(A.begin(),A.end());
    find(A,ans,res,v,i,n);
    set<vector<int>>::iterator it;
    for(it=ans.begin();it!=ans.end();it++){
        res.push_back(*it);
    }
    
    return res;
}
