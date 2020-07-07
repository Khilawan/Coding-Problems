/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isPalindrome(string A) {
    
    vector<int>s;
    for(int i=0;i<A.size();i++){
        int ch=A[i];
        if(ch>=65&&ch<=90){
            s.push_back(ch%65);
        }else if(ch>=97&&ch<=122){
            s.push_back(ch%97);
        }else if(ch>=48&&ch<=57){
            s.push_back(ch);
        }
    }
    int l=0,r=s.size()-1;
    while(l<r){
        
        if(s[l]!=s[r]){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}
