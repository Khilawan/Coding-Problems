/*
Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 7

bool isword(string &str,set<string> &s,int z,set<string> &ss){

    if(s.find(str)!=s.end()&&ss.find(str)==ss.end()){
        return true;
    }
    return false;
}

void find(string &str,set<string> &s,char b[MAX][MAX],int sol[MAX][MAX],int z,int n,int m,int x,int y,int mx,set<string> &ss){
    if(str.length()>mx){
        return;
    }
    str.push_back(b[x][y]);
    sol[x][y]=1;
    if(isword(str,s,z,ss)){
        ss.insert(str);
    }    
    for(int r=x-1;r<=x+1&&r<n;r++){
        for(int c=y-1;c<=y+1&&c<m;c++){
            if(r>=0&&c>=0&&sol[r][c]==0)
                find(str,s,b,sol,z,n,m,r,c,mx,ss);
        }
    }
    str.pop_back();
    sol[x][y]=0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        set<string> s;
        int maxlen=0;
        set<string> ss;
        for(int i=0;i<x;i++){
            string sy;
            cin>>sy;
            if(maxlen<sy.length()){
                maxlen=sy.length();
            }
            s.insert(sy);
        }
        int n,m;
        cin>>n>>m;
        char b[MAX][MAX];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>b[i][j];
            }
        }
        int sol[MAX][MAX];
        string str="";
        memset(sol,0,sizeof(sol));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                find(str,s,b,sol,x,n,m,i,j,maxlen,ss);
            }
        }
        set<string>::iterator it;
        if(ss.size()==0){
            cout<<-1<<endl;
            continue;
        }
        for(it=ss.begin();it!=ss.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}