/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.


The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isValidSudoku(const vector<string> &A) {
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            set<char>s;
            for(int k=0;k<9;k++){
                if(A[i][k]!='.'&&s.find(A[i][k])!=s.end()){
                    return 0;
                }else if(A[i][k]!='.'){
                    s.insert(A[i][k]);
                }
            }
            s.clear();
            for(int k=0;k<9;k++){
                if(A[k][j]!='.'&&s.find(A[k][j])!=s.end()){
                    return 0;
                }else if(A[k][j]!='.'){
                    s.insert(A[k][j]);
                }
            }
            s.clear();
            int r=i-i%3;
            int c=j-j%3;
            for(int k=r;k<r+3;k++){
                for(int l=c;l<c+3;l++){
                    if(A[k][l]!='.'&&s.find(A[k][l])!=s.end()){
                        return 0;
                    }else if(A[k][l]!='.'){
                        s.insert(A[k][l]);
                    }
                }
            }
            s.clear();
        }
    }
    
    return 1;
}
