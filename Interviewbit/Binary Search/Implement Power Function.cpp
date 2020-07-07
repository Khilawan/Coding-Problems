/*
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.
*/

int mypow(long long x, int n, int d){
    
    if(x==0){
        return 0;
    }else if(n==1){
        return (x%d);
    }else if(n==0){
        return 1;
    }
    
    x=x%d;
    if(n%2==0){
            
            return mypow((x*x)%d,n/2,d)%d;
    }
    return ((mypow((x*x)%d,(n-1)/2,d)%d)*x)%d;
}

int Solution::pow(int x, int n, int d) {
    
    int num=mypow(x,n,d);
    if(num<0){
        return d+num;
    }
    return num;
}