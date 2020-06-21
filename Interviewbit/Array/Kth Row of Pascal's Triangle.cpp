/*
Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
*/
vector<int> Solution::getRow(int A) {
    vector<int> v;
    int n=1;
    for(int i=0;i<=A;i++){
        v.push_back(n);
        n=n*(A-i)/(i+1);
    }
    return v;
}
