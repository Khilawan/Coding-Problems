/*
Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (n-1, n-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

Example
Input:
3
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
2
1 0 1 0 

Output:
DRDDRR
DDRDRR DRDDRR
-1
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

bool issafe(int m[][MAX],int sol[MAX][MAX],int x,int y,int n){
    if(x>=0&&x<n&&y>=0&&y<n&&sol[x][y]==0&&m[x][y]==1){
        return true;
    }
    return false;
}

void find(int m[][MAX],int x,int y,vector<string>&s,string& ch,int n,int sol[MAX][MAX]){
    if(x<0||x>=n||y<0||y>=n||sol[x][y]==1||m[x][y]==0){
        return;
    }
    if(x==n-1&&y==n-1){
        s.push_back(ch);
        return;
    }
    sol[x][y]=1;
    if(issafe(m,sol,x+1,y,n)==true){
        ch.push_back('D');
        find(m,x+1,y,s,ch,n,sol);
        ch.pop_back();
    }
    if(issafe(m,sol,x,y-1,n)==true){
        ch.push_back('L');
        find(m,x,y-1,s,ch,n,sol);
        ch.pop_back();
    }
    if(issafe(m,sol,x,y+1,n)==true){
        ch.push_back('R');
        find(m,x,y+1,s,ch,n,sol);
        ch.pop_back();
    }
    if(issafe(m,sol,x-1,y,n)==true){
        ch.push_back('U');
        find(m,x-1,y,s,ch,n,sol);
        ch.pop_back();
    }
    sol[x][y]=0;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string>s;
    string ch;
    int sol[MAX][MAX];
    memset(sol,0,sizeof(sol));
    find(m,0,0,s,ch,n,sol);
    return s;
}
