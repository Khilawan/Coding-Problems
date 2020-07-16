/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

Example :

Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
    
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])

*/


vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    vector<vector<int>>res;
    
    int n=A.size();
    if(n<4){
        return res;
    }
    sort(A.begin(),A.end());
    
    for(int i=0;i<n-3;i++){
        if(i>0&&A[i]==A[i-1]){
            continue;
        }
        if(A[i]+A[i+1]+A[i+2]+A[i+3]>B)break;
        if(A[i]+A[n-1]+A[n-2]+A[n-3]<B)continue;;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1&&A[j]==A[j-1]){
                continue;
            }
            if(A[i]+A[j+1]+A[j+2]+A[j]>B)break;
            if(A[i]+A[j]+A[n-2]+A[n-1]<B)continue;
            
            int l=j+1,r=n-1;
            while(l<r){
                int sum=A[i]+A[j]+A[l]+A[r];
                if(sum>B){
                    r--;
                }else if(sum<B){
                    l++;
                }else{
                    res.push_back(vector<int>{A[i],A[j],A[l],A[r]});
                    do{
                        l++;
                    }while(A[l]==A[l-1]&&l<r);
                    do{
                        r--;
                    }while(A[r]==A[r+1]&&l<r);
                }
            }
                
                
        }
    }
    
    return res;
}

  