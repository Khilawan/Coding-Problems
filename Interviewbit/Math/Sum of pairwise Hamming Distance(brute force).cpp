/*
Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

Given an array A of N non-negative integers, 
find the sum of hamming distances of all pairs of integers in the array. 
Return the answer modulo 1000000007.



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

//brute force

int setbits(int num, int *ones, int *zeros){
    
    while(num){
        if(num%2==0){
            (*zeros)++;
        }else{
            (*ones)++;
        }
        num>>=1;
    }
}

int Solution::hammingDistance(const vector<int> &A) {
    int n=A.size();
    if(n<2){
        return 0;
    }
    int sum=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(i!=j){
                int num=A[i]^A[j];
                sum+=setbits(num)%1000000007;
            }
        }
    }
    sum=(sum+sum)%1000000007;
    return sum;
}
