/*
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

    1. Insert
    2. Remove
    3. Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Example:
Input:
1
4 5
geek gesek

Output:
1
*/

#include<bits/stdc++.h>
using namespace std;

int editD(string s1,string s2, int n,int m){
    int tab[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                tab[i][j]=j;
            }else if(j==0){
                tab[i][j]=i;
            }else if(s1[i-1]==s2[j-1]){
                tab[i][j]=tab[i-1][j-1];
            }else{
                tab[i][j]=1+min(min(tab[i-1][j],tab[i][j-1]),tab[i-1][j-1]);
            }
        }
    }
    return tab[n][m];
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
        cout<<editD(s1,s2,n,m)<<endl;
    }
	return 0;
}