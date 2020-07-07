/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003
*/

int facto(int n){
    if(n<=1){
        return 1;
    }
    return (n*facto(n-1))%1000003;
}

int Solution::findRank(string A) {

    
    int n=A.size();
    int a[n];

    for(int i=0;i<n;i++){
        a[i]=0;
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j]){
                a[i]++;
            }
        }
    }
    
    int count=1;
    for(int i=0;i<n;i++){
        count+=(a[i]*facto(n-i-1))%1000003;
    }
    return count%1000003;
}
