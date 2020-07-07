/*
Given a number N, find all prime numbers upto N ( N included ).

Example:

if N = 7,

all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.
*/

bool isprime(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

vector<int> Solution::sieve(int A) {
    vector<int>prime;
    for(int i=2;i<=A;i++){
        if(isprime(i)){
            prime.push_back(i);
        }
    }
    return prime;
}
