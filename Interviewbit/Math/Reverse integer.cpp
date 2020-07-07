/*
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer
*/

int Solution::reverse(int A) {
    long num=0;
    
    while(A){
        num*=10;
        num+=A%10;
        A/=10;
    }
    
    if(num<INT_MIN||num>INT_MAX){
        return 0;
    }
    A=num;
    
    return A;
}
