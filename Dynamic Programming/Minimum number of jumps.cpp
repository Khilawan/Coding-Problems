/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). 
If an element is 0, then cannot move through that element.

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2
*/

#include<bits/stdc++.h>
using namespace std;

int ifind(long a[],int n){
    if(a[0]==0||n==0){
        return -1;
    }
    
    long b[n];
    b[0]=0;
    for(int i=1;i<n;i++){
        b[i]=INT_MAX;
        for(int j=0;j<i;j++){
            if(i<=a[j]+j&&b[j]!=INT_MAX){
                b[i]=min(b[i],1+b[j]);
                break;
            }
        }
    }
    if(b[n-1]==INT_MAX){
        return -1;
    }
    return b[n-1];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        long a[n];
        for(long i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<ifind(a,n)<<endl;
    }
	return 0;
}