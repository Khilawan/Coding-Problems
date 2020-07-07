/*
Problem Description

Reverse the bits of an 32 bit unsigned integer A.

Example Input
Input 1:
 0

Input 2:
 3


Example Output
Output 1:
 0

Output 2:
 3221225472
*/

unsigned int Solution::reverse(unsigned int A) {
   
    if(A==0){
        return 0;
    }
    vector<int>bits(32);
    int i=0;
    unsigned int total=0;
    while(i<32){
        int bit=A%2;
        total+=pow(2,31-i)*bit;
        A>>=1;
        i++;
    }
    return total;
}
