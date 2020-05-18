/*
Given an array A[ ] denoting heights of N towers and a positive integer K, 
modify the heights of each tower either by increasing or decreasing them by K only once and then find out the minimum difference of the heights of shortest and longest towers.

Examples 
Input
3
2
4
1 5 8 10
3
5
3 9 12 16 20
4
6
100 150 200 250 300 400

Output
5
11
292
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int res=a[n-1]-a[0];
        int max=a[n-1]-k;
        int min=a[0]+k;
        if(max<min){
            swap(max,min);
        }
        for(int i=1;i<n-1;i++){
            int add=a[i]+k;
            int subs=a[i]-k;
            if(add<=max||subs>=min){
                continue;
            }
            if(max-subs<=add-min){
                min=subs;
            }else{
                max=add;
            }
        }
        if(res<(max-min)){
            cout<<res<<endl;    
        }else{
            cout<<(max-min)<<endl;
        }
        
    }
	return 0;
}