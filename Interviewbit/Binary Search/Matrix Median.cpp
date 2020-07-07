/*
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.


Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17
*/

int Solution::findMedian(vector<vector<int> > &A) {
    int s=INT_MAX,e=INT_MIN;
    int r=A.size(),c=A[0].size();
    int k=(r*c+1)/2;
    
    for(int i=0;i<r;i++){
        s=min(s,A[i][0]);
        e=max(e,A[i][c-1]);
    }
    
    while(s<=e){
        int place=0;
        int mid=(s+e)/2;
        for(int i=0;i<r;i++){
            place+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        
        if(place<k){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return s;
}
