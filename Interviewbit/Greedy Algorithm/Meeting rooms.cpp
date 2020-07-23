/*
Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.

Find the minimum number of conference rooms required so that all meetings can be done.

Problem Constraints
1 <= N <= 10

0 <= A[i][0] < A[i][1] <= 2 * 109

Input Format
The only argument given is the matrix A.

Output Format
Return the minimum number of conference rooms required so that all meetings can be done.

Example Input
Input 1:

 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:

 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]


Example Output

Output 1:
 2

Output 2:
 4


*/


int Solution::solve(vector<vector<int> > &A) {
    map<int,int>m;
    for(int i=0;i<A.size();i++){
        m[A[i][0]]++;
        m[A[i][1]]--;
    }
    int count=0;
    int mx=INT_MIN;
    for(auto it=m.begin();it!=m.end();it++){
        count+=it->second;
        mx=max(mx,count);
    }
    
    return mx;
}
