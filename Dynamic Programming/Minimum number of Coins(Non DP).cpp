/*
Given a value N, total sum you have. You have to make change for Rs. N, and there is infinite supply of each of the denominations in Indian currency, i.e., you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, Find the minimum number of coins and/or notes needed to make the change for Rs N.

Example:
Input:
1
43

Output:
20 20 2 1
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int cur[]={2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int m=10;
    while(t--){
        int num[m];
        memset(num,0,sizeof(int)*m);
        int total;
        cin>>total;
        for(int i=0;i<m;i++){
            if(total/cur[i]!=0){
                int n=total/cur[i];
                total=total%cur[i];
                num[i]=n;
            }
        }
        for(int i=0;i<m;i++){
            if(num[i]!=0){
                for(int j=0;j<num[i];j++){
                    cout<<cur[i]<<" ";
                }
            }
        }
        cout<<endl;
    }
	return 0;
}