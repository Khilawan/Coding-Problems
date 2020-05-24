/*
Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

Example:
Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3
*/

#include<bits/stdc++.h>
using namespace std;

int lis(int a[],int n){
    if(n==1){
        return 1;
    }
    int tab[n];
    for(int i=0;i<n;i++){
        tab[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&tab[i]<tab[j]+1){
                tab[i]=tab[j]+1;
            }
        }
    }
    int max=1;
    for(int i=0;i<n;i++){
        if(max<tab[i]){
            max=tab[i];
        }
    }
    return max;
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
        cout<<lis(a,n)<<endl;
    }
	return 0;
}