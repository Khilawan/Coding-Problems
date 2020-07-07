/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 
*/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    vector<vector<int>>res;
    int n=A.size();
    if(n<=2){
        return res;
    }
    sort(A.begin(),A.end());
    for(int i=0;i<n-2;i++){
        if(i!=0&&A[i]==A[i-1]){
            continue;
        }
        if(A[i]>0){
            break;
        }
        int l=i+1;
        int r=n-1;
        while(l<r){
            long int a=A[i],ll=A[l],rr=A[r];
            long int sum=a+ll+rr;
            if(sum==0){
                res.push_back(vector<int>({A[i],A[l],A[r]}));
                while(l<r&&ll==A[++l]);
                while(l<r&&rr==A[--r]);
            }else if(sum>0){
                r--;
            }else if(sum<0){
                l++;
            }
        }
    }
    return res;
}