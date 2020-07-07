/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size()<3){
        return 0;
    }
    
    int closes=INT_MAX;
    int n=A.size();
    int res;
    int i=0;
    
    sort(A.begin(),A.end());
    
    while(i<n-2){
        
        int l=i+1;
        int r=n-1;
        while(l<r){
            
            int tmp=A[i]+A[l]+A[r];
            int d=abs(B-tmp);
            
            if(d==0){
                return B;
            }
            if(d<closes){
                closes=d;
                res=tmp;
            }
            if(tmp<B){
                l++;
            }else{
                r--;
            }
        }
        i++;
    }
    return res;
}

    