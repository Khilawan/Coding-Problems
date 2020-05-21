/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Example:
Input:
2
3
4
1 2 3
4 5 1
3
3
1 2 3
4 5 6
Output:
3
0
*/

#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int wt[],int n,int w){
    int knap[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0){
                knap[i][j]=0;
            }else if(wt[i-1]<=j){
                //knap[i][j]=max(knap[i-1][j],val[i-1]+knap[i-1][j-wt[i-1]]);
                if(knap[i-1][j]>val[i-1]+knap[i-1][j-wt[i-1]]){
                    knap[i][j]=knap[i-1][j];
                }else{
                    knap[i][j]=val[i-1]+knap[i-1][j-wt[i-1]];
                }
            }else{
                knap[i][j]=knap[i-1][j];
            }
        }
    }
    return knap[n][w];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int val[n], wt[n];
        
        for(int i=0;i<n;i++){
            cin>>val[i];
        }
        for(int i=0;i<n;i++){
            cin>>wt[i];
        }
        
        cout<<knapsack(val,wt,n,w)<<endl;
    }
	return 0;
}