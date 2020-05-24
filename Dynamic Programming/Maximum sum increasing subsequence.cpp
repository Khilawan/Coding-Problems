/*
Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

Example:
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10
*/
#include<bits/stdc++.h>
using namespace std;

int msis(int a[],int n){
    int tabsum[n];
    for(int i=0;i<n;i++){
        tabsum[i]=a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&tabsum[i]<tabsum[j]+a[i]){
                tabsum[i]=tabsum[j]+a[i];
            }
        }
    }
    int maxsum=0;
    for(int i=0;i<n;i++){
        if(maxsum<tabsum[i]){
            maxsum=tabsum[i];
        }
    }
    return maxsum;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<msis(a,n)<<endl;
    }
	return 0;
}