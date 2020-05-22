/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other. 
Given an integer n, print all distinct solutions to the n-queens puzzle. 
Each solution contains distinct board configurations of the n-queens’ placement, 
where the solutions are a permutation of [1,2,3..n] in increasing order, 
here the number in the ith place denotes that the ith-column queen is placed in the row with that number. 
For eg below figure represents a chessboard [3 1 4 2].

Example:
Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 10

bool issafe(vector<int> &vv,int sol[MAX][MAX],int c,int r,int n){
    for(int i=0;i<n;i++){
        if(sol[r][i]==1){
            return false;
        }
    }
    for(int i=r,j=c;i>=0&&j>=0;i--,j--){
        if(sol[i][j]==1){
            return false;
        }
    }
    for(int i=r,j=c;i<n&&j>=0;i++,j--){
        if(sol[i][j]==1){
            return false;
        }
    }
    return true;
}
int flag=0;
void find(vector<vector<int>>&v,vector<int> &vv,int sol[MAX][MAX],int c,int n){
    if(c>=n){
        cout<<"[";
        for(int i=0;i<n;i++){
            cout<<vv[i]+1<<" ";
        }
        cout<<"] ";
        flag=1;
        return;
    }
    for(int i=0;i<n;i++){
        if(issafe(vv,sol,c,i,n)){
            sol[i][c]=1;
            vv.push_back(i);
            find(v,vv,sol,c+1,n);
            vv.pop_back();
            sol[i][c]=0;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sol[MAX][MAX];
        memset(sol,0,sizeof(sol));
        vector<vector<int>>v;
        vector<int>vv;
        flag=0;
        find(v,vv,sol,0,n);
        if(flag==1){
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
	return 0;
}