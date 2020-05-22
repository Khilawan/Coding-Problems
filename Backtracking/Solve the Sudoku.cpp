/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (mat[][]). The task to print a solved Sudoku. 
For simplicity you may assume that there will be only one unique solution.

Example:
Input:
1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

Output:
3 1 6 5 7 8 4 9 2 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 2 6 3 4 1 5 9 8 7 9 7 4 8 6 3 1 2 5 8 5 1 7 9 2 6 4 3 1 3 8 9 4 7 2 5 6 6 9 2 3 5 1 8 7 4 7 4 5 2 8 6 3 1 9

*/

#include<bits/stdc++.h>
using namespace std;

bool check(int m[9][9],int &r,int &c){
    for(r=0;r<9;r++){
        for(c=0;c<9;c++){
            if(m[r][c]==0){
                return true;
            }
        }
    }
    return false;
}

bool row(int m[9][9],int r,int num){
    for(int i=0;i<9;i++){
        if(m[r][i]==num){
            return true;
        }
    }
    return false;
}
bool col(int m[9][9],int c,int num){
    for(int i=0;i<9;i++){
        if(m[i][c]==num){
            return true;
        }
    }
    return false;
}

bool block(int m[9][9],int r,int c,int num){
    for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
            if(m[i][j]==num){
                return true;
            }
        }
    }
    return false;
}

bool suit(int m[9][9],int r,int c,int num){
    return !row(m,r,num)&&!col(m,c,num)&&!block(m,r-r%3,c-c%3,num);
}

bool find(int m[9][9]){
    int r,c;
    if(!check(m,r,c)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(suit(m,r,c,i)){
            m[r][c]=i;
            if(find(m)){
                return true;
            }
            m[r][c]=0;
        }
    }
    return false;
}

void print(int m[9][9]){
    if(find(m)){
    //find(m);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<m[i][j]<<" ";
            }
        }
        return;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int m[9][9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>m[i][j];
            }
        }
        if(find(m)){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<m[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
