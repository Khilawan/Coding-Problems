/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False
*/

int reverse(long a){

    long num=0;
    while(a){
        num=num*10;
        num+=(a%10);
        a=a/10;
    }
    return num;
}

int Solution::isPalindrome(int A) {
    if(A<0){
        return 0;
    }
    int rev=reverse(A);
    if(rev==A){
        return 1;
    }
    return 0;
}
