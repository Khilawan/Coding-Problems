/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Example:
Input:
2
4
1 5 11 5
3
1 3 5 

Output:
YES
NO
*/

#include<bits/stdc++.h>
using namespace std;

bool subsum(int a[],int n,int sum){
    bool tab[n+1][sum+1];
    
    for(int i=0;i<=n;i++){
        tab[i][0]=true;
    }
    for(int i=1;i<=sum;i++){
        tab[0][i]=false;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<a[i-1]){
                tab[i][j]=tab[i-1][j];
            }else{
                tab[i][j]=tab[i-1][j]||tab[i-1][j-a[i-1]];
            }
        }
    }
    
    return tab[n][sum];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        sum/=2;
        if(subsum(a,n,sum)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
	return 0;
}