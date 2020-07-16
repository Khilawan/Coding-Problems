/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

*/

void find(vector<vector<int>>&v,vector<int>&res,vector<int>num,int ind,int sum,int n){
    if(sum<0){
        return;
    }
    if(sum==0){
        v.push_back(res);
        return;
    }
    if(ind>=n){
        return;
    }
    res.push_back(num[ind]);
    find(v,res,num,ind+1,sum-num[ind],n);
    res.pop_back();
    while(ind<n-1&&num[ind]==num[ind+1])ind++;
    find(v,res,num,ind+1,sum,n);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector<int>>res;
    vector<int>v;
    int sum=0;
    find(res,v,A,0,B,A.size());
    return res;
}
