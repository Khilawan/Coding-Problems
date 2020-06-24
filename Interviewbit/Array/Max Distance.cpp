/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)
*/

int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2){
        return 0;
    }
    
    vector<pair<int,int>>m;
    for(int i=0;i<A.size();i++){
        m.push_back(make_pair(A[i],i));
    }
    sort(m.begin(),m.end());
    int res=0;
    int ind=m[m.size()-1].second;
    for(int i=m.size()-2;i>=0;i--){
        res=max(res,ind-m[i].second);
        ind=max(ind,m[i].second);
    }
    
    return res;
}
