/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int t=0,b=A.size()-1,r=A[0].size()-1,l=0;
    int dir=0;
    vector<int> B;
    
    while(t<=b&&l<=r){
        if(dir==0){
            for(int i=l;i<=r;i++){
                B.push_back(A[t][i]);
            }
            dir=1;
            t++;
        }else if(dir==1){
            for(int i=t;i<=b;i++){
                B.push_back(A[i][r]);
            }
            r--;
            dir=2;
        }else if(dir==2){
            for(int i=r;i>=l;i--){
                B.push_back(A[b][i]);
            }
            b--;
            dir=3;
        }else if(dir==3){
            for(int i=b;i>=t;i--){
                B.push_back(A[i][l]);
            }
            dir=0;
            l++;
        }
    }
    return B;
}
