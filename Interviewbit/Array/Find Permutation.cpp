/*
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

    1. Length of given string s will always equal to n - 1
    2. Your solution should run in linear time and space.
    
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]
*/
vector<int> Solution::findPerm(const string A, int B) {
    vector<int> a(B);
    if(A[0]=='I'){
        a[0]=-1;
    }else if(A[0]=='D'){
        a[0]=1;
    }
    for(int i=0;i<A.size();i++){
        if(A[i]=='D'){
            a[i+1]=-1;
        }else if(A[i]=='I'){
            a[i+1]=1;
        }
    }
    int num=B;
    for(int i=B-1;i>=0;i--){
        if(a[i]==1){
            a[i]=num--;
        }
    }
    for(int i=0;i<B;i++){
        if(a[i]==-1){
            a[i]=num--;
        }
    }
    return a;
    
}
