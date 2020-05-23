/*
Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
*/

#include<bits/stdc++.h>
using namespace std;

int scs(string s1,string s2,int x,int y){
    int tab[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0||j==0){
                tab[i][j]=0;
            }else if(s1[i-1]==s2[j-1]){
                tab[i][j]=1+max(tab[i][j-1],tab[i-1][j]);
            }else{
                tab[i][j]=max(tab[i][j-1],tab[i-1][j]);
            }
        }
    }
    return (x+y-tab[x][y]);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<scs(s1,s2,s1.size(),s2.size())<<endl;
    }
	return 0;
}