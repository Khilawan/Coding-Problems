/*
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

    1. X divides A i.e. A % X = 0
    2. X and B are co-prime i.e. gcd(X, B) = 1

For example,

A = 30
B = 12
We return
X = 5
*/

int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0){
        return a;
    }
    return gcd(a%b,b);
}

int Solution::cpFact(int A, int B) {
    while(gcd(A,B)!=1){
        A=A/(gcd(A,B));
    }
    return A;
}
