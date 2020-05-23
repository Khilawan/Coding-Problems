/*
Given two strings X and Y. The task is to find the length of the longest common substring.

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1
*/

#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int n, int m){
    int tab[n+1][m+1];
    int maxsum=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                tab[i][j]=0;
            }else if(s1[i-1]==s2[j-1]){
                tab[i][j]=1+tab[i-1][j-1];
                if(maxsum<tab[i][j]){
                    maxsum=tab[i][j];
                }
            }else{
                tab[i][j]=0;
            }
        }
    }
    return maxsum;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        cout<<lcs(s1,s2,n,m)<<endl;
    }
	return 0;
}