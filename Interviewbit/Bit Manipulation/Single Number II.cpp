/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

For Examples :

Example Input 1:
    A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Example Output 1:
    4
Explanation:
    4 occur exactly once
Example Input 2:
    A = [0, 0, 0, 1]
Example Output 2:
    1
*/

int Solution::singleNumber(const vector<int> &A) {
    
    int a[32];
    memset(a,0,sizeof(a));
    int res=0;
    
    for(int i=0;i<32;i++){
        for(int j=0;j<A.size();j++){
            if(A[j]>>i&1){
                a[i]++;
            }
            //a[i]+=A[j]>>i&1;
            
        }
        res|=(a[i]%3)<<i;
    }
    return res;
}