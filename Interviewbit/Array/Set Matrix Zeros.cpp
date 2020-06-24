/*
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int m=A[0].size();
    int r[n],c[m];
    
    memset(r,1,sizeof(r));
    memset(c,1,sizeof(c));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==0){
                r[i]=0;
                c[j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(r[i]==0){
            for(int j=0;j<m;j++){
                A[i][j]=0;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(c[i]==0){
            for(int j=0;j<n;j++){
                A[j][i]=0;
            }
        }
    }
}
