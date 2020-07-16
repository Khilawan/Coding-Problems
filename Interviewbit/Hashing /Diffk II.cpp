/*
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2

Output :
1
as 3 - 1 = 2

Return 0 / 1 for this problem.
*/

int Solution::diffPossible(const vector<int> &A, int B) {
    set<int>s;
    int n=A.size();
    s.insert(A[0]+B);
    s.insert(A[0]-B);
    for(int i=1;i<n;i++){
        if(s.find(A[i])!=s.end()){
            return 1;
        }
        s.insert(A[i]+B);
        s.insert(A[i]-B);
    }
    return 0;
}
