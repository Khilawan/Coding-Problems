/*
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"
*/

string Solution::longestPalindrome(string A) {
    
    if(A.size()<=1){
        return A;
    }

    int maxlen=1;
    int ml=0,mr=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(A[l]==A[r]&&l>=0&&r<n){
            int len=r-l+1;
            if(maxlen<len){
                maxlen=len;
                ml=l;
                mr=r;
            }
            l--;
            r++;
        }
        l=i,r=i+1;
        while(A[l]==A[r]&&l>=0&&r<n){
            int len=r-l+1;
            if(maxlen<len){
                maxlen=len;
                ml=l;
                mr=r;
            }
            l--;
            r++;
        }
    }
    string s="";
    for(int i=ml;i<=mr;i++){
        s+=A[i];
    }
    return s;
}
