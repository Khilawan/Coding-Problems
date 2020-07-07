/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.
*/

int Solution::lengthOfLastWord(const string A) {
    if(A.size()==0){
        return 0;
    }
    int n=A.size()-1,len=0,flag=0;
    for(int i=n;i>=0;i--){
        if(A[i]==' '&&flag){
            break;
        }else if(A[i]!=' '){
           len++;
           flag=1;
        }
    }
    
    return len;
}
