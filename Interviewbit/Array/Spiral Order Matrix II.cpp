/*
Given an integer A, generate a square matrix filled with elements from 1 to A^2 in spiral order.

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    int t=0,b=A-1,l=0,r=A-1;
    vector<vector<int>>a;
    int dir=0;
    int val=1;
    for(int i=0;i<A;i++){
        vector<int>v;
        for(int j=0;j<A;j++){
            v.push_back(0);
        }
        a.push_back(v);
    }
    while(t<=b&&l<=r){
        if(dir==0){
            for(int i=l;i<=r;i++){
                a[t][i]=val++;
            }
            t++;
            dir=1;
        }else if(dir==1){
            for(int i=t;i<=b;i++){
                a[i][r]=val++;
            }
            r--;
            dir=2;
        }else if(dir==2){
            for(int i=r;i>=l;i--){
                a[b][i]=val++;
            }
            b--;
            dir=3;
        }else if(dir==3){
            for(int i=b;i>=t;i--){
                a[i][l]=val++;
            }
            l++;
            dir=0;
        }
    }
    return a;
}
