/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
*/

vector<int> Solution::flip(string A) {
    vector<int> v;
    vector<int> lr;
    for(int i=0;i<A.size();i++){
        if(A[i]=='0'){
            v.push_back(1);
        }else{
            v.push_back(-1);
        }
    }
    int l=0,r=0,ml=0,mr=0;
    int maxsum=INT_MIN,sum=0;
    int flag=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        
        if(sum<0){
            l=i+1;
            r=i+1;
            sum=0;
            continue;
        }
        if(maxsum<sum){
            flag=1;
            maxsum=sum;
            ml=l;
            mr=i;
        }
        r++;
    }
    if(flag){
        lr.push_back(++ml);
        lr.push_back(++mr);
    }
    
    return lr;
}
