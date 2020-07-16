/*
Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Problem Constraints
1 <= |A| <= 100000



Input Format
The only argument given is integer array A.



Output Format
Return the total water it is able to trap after raining.



Example Input

Input 1:

 A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

Input 2:

 A = [1, 2]


Example Output
Output 1:
 6

Output 2:
 0

*/

int Solution::trap(const vector<int> &A) {
    int n=A.size();
    int a[n]={0};
    int b[n]={0};
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        mx=max(A[i],mx);
        a[i]=mx;
    }
    mx=INT_MIN;
    for(int i=n-1;i>=0;i--){
        mx=max(A[i],mx);
        b[i]=mx;
    }
    
    int sum=0;
    
    for(int i=0;i<n;i++){
        sum+=min(a[i],b[i])-A[i];
    }
    
    return sum;
}
