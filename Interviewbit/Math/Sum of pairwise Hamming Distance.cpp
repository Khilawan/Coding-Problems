/*
Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array. Return the answer modulo 1000000007.



Problem Constraints
1 <= |A| <= 200000

1 <= A[i] <= 109



Input Format
First and only argument is array A.



Output Format
Return one integer, the answer to the problem.



Example Input
Input 1:

 A = [1]
Input 2:

 A = [2, 4, 6]


Example Output
Output 1:

 0
Output 2:

 8

*/

int Solution::hammingDistance(const vector<int> &A) {
    long sum=0;
    long n=A.size();
    if(n<2){
        return 0;
    }
    for(int i=0;i<32;i++){
        int num=0;
        for(int j=0;j<n;j++){
            if(A[j] & 1<<i){
                num++;
            }
        }
        sum+=(2*(n-num)*num)%1000000007;
        sum=sum%1000000007;
    }
    
    return (int)sum;
}

    