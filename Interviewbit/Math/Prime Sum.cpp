/*
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d.
*/

bool isprime(int a){
    for(int i=2;i<a;i++){
        if(a%i==0){
            return false;
        }
    }    
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> v(2);
    for(int i=2;i<=A/2;i++){
        if(isprime(i)&&isprime(A-i)){
            v[0]=i;
            v[1]=A-i;
            break;
        }
    }
    return v;
}
