/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

*/

void find(int A,int B,vector<vector<int>> &res,vector<int>&v,int val){

    
    if(v.size()==B){
        res.push_back(v);
        return;
    }
    
    if(val>A){
        return;
    }
        
    for(int i=val;i<=A;i++){
        v.push_back(i);
        find(A,B,res,v,i+1);
        v.pop_back();
    }

    /*
    v.push_back(val);
    find(A,B,res,v,val+1);
    v.pop_back();
    find(A,B,res,v,val+1);
    */
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<int>v;
    vector<vector<int>>res;
    if(A<B){
        return res;
    }
    find(A,B,res,v,1);
    return res;
}
