/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

*/
//O(n) extra space
int Solution::firstMissingPositive(vector<int> &A) {
    int n=A.size();
    int a[n+1];
    
    memset(a,0,sizeof(a));
    
    for(int i=0;i<n;i++){
        if(A[i]>0&&A[i]<=n){
            a[A[i]]++;
        }
    }
    int flag=1;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            return i;
        }else if(a[i]<0){
            flag=0;
        }
    }
    
    if(flag){
        return (n+1);
    }
    return 1;
}
