/*
Given a value N, find the number of ways to make change for N cents, 
if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. 
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.

Example:
Input:
2
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5
*/
#include<bits/stdc++.h>
using namespace std;

int coin(int a[],int m,int n){
    int tab[n+1];
    for(int i=0;i<=n;i++){
        tab[i]=0;
    }
    tab[0]=1;
    for(int i=0;i<m;i++){
        for(int j=a[i];j<=n;j++){
            tab[j]+=tab[j-a[i]];
        }
    }
    return tab[n];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m;
        int a[m];
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        cin>>n;
        cout<<coin(a,m,n)<<endl;
    }
	return 0;
}