/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


*/

bool issafe(vector<string>&v, int A,int c,int r){
    for(int i=0;i<A;i++){
        if(v[r][i]=='Q'){
            return false;
        }
    }
    
    for(int i=r,j=c;i<A&&j>=0;i++,j--){
        if(v[i][j]=='Q'){
            return false;
        }
    }
    
    for(int i=r,j=c;i>=0&&j>=0;i--,j--){
        if(v[i][j]=='Q'){
            return false;
        }
    }
    
    return true;
}


void find(vector<string>&v, vector<vector<string> >&res, int A,int c){
    if(c>=A){
        res.push_back(v);
        return;
    }
    
    for(int i=0;i<A;i++){
        if(issafe(v,A,c,i)){
            v[i][c]='Q';
            find(v,res,A,c+1);
            v[i][c]='.';
        }
    }
}


vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string> >res;
    vector<string>v;
    for(int i=0;i<A;i++){
        string s="";
        for(int j=0;j<A;j++){
            s+='.';
        }
        v.push_back(s);
    }
    find(v,res,A,0);
    
    return res;
}
