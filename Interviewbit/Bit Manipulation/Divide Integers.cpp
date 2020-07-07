/*
Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

Note: INT_MAX = 2^31 - 1
*/

int Solution::divide(int A, int B) {
    long long q=0;
    long long a=A,b=B;
    int sign;
    if(b==1){
        return a;
    }
    sign=a<0^b<0?-1:1;
    a=abs(a);
    b=abs(b);
    for(int t=0,i=31;i>=0;i--){
        if(t+(b<<i)<=a){
            t+=b<<i;
            q|=1ll<<i;
        }
    }
    if(sign<0){
        q=-q;
    }
    return q>=INT_MAX||q<INT_MIN?INT_MAX:q;
}