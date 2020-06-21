/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> B(2);
    long long sum=0;
    long long sqsum=0;
    long long tmp=0;
    for(int i=0;i<A.size();i++){
        tmp=A[i];
        sum+=tmp;
        sum-=(i+1);
        sqsum+=tmp*tmp;
        sqsum-=(long long)(i+1)*(long long)(i+1);
    }
    sqsum/=sum;
    B[0]=(int)((sum+sqsum)/2);
    B[1]=(int)(sqsum-B[0]);
    return B;
}
