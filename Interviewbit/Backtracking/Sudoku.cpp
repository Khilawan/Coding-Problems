/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'
You may assume that there will be only one unique solution.


Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]

and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

*/

bool check(vector<vector<char> > &m,int &r,int &c){
    for(r=0;r<9;r++){
        for(c=0;c<9;c++){
            if(m[r][c]=='.'){
                return true;
            }
        }
    }
    return false;
}

bool row(vector<vector<char> > &m,int r,int num){
    char ch=num+'0';
    for(int i=0;i<9;i++){
        if(m[r][i]==ch){
            return true;
        }
    }
    return false;
}
bool col(vector<vector<char> > &m,int c,int num){
    char ch=num+'0';
    for(int i=0;i<9;i++){
        if(m[i][c]==ch){
            return true;
        }
    }
    return false;
}

bool block(vector<vector<char> > &m,int r,int c,int num){
    char ch=num+'0';
    for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
            if(m[i][j]==ch){
                return true;
            }
        }
    }
    return false;
}

bool suit(vector<vector<char> > &m,int r,int c,int num){
    return !row(m,r,num)&&!col(m,c,num)&&!block(m,r-r%3,c-c%3,num);
}

bool find(vector<vector<char> > &m){
    int r,c;
    if(!check(m,r,c)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(suit(m,r,c,i)){
            m[r][c]=i+'0';
            if(find(m)){
                return true;
            }
            m[r][c]='.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    if(find(A)){
        return;
    }
}
