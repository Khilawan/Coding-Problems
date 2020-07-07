/*
Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY



Input Format

The first and only argument given is the integer A.
Output Format

Return floor(sqrt(A))
Constraints

1 <= A <= 10^9
For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3
*/

int Solution::sqrt(int A) {
    if(A==0)return 0;
    int s=1,e=A;
    int val=1;
    while(s<=e){
        int mid=(s+e)/2;
        if(mid<=A/mid){
            s=mid+1;
            val=mid;
        }else{
            e=mid-1;
        }
        
    }
    return val;
}
