/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.

Example,
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]

*/


void find(vector<int> &A,int B,vector<vector<int> >&res,vector<int>&v,int sum,int i){
    if(i>=A.size()){
        return;
    }
    if(sum>B){
        return;
    }else if(sum==B){
        res.push_back(v);
        return;
    }
    
    for(int j=i;j<A.size();j++){
        sum+=A[j];
        v.push_back(A[j]);
        find(A,B,res,v,sum,j);
        sum-=A[j];
        v.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector<int> > res;
    vector<int>v;
    int sum=0;
    int i=0;
    vector<int>vv;
    vv.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        if(A[i]!=A[i-1]){
            vv.push_back(A[i]);
        }
    }
    
    find(vv,B,res,v,sum,i);
    return res;
}
