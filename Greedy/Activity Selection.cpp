/*
Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Example:
Input:
2
6
1 3 2 5 8 5
2 4 6 7 9 9
4
1 3 2 5
2 4 3 6

Output:
4
4
*/

#include<bits/stdc++.h>
using namespace std;

struct mtime{
    int s;
    int f;
};

bool comparex(mtime a,mtime b){
    return (a.f<b.f);
}

void ifind(mtime sf[],int n){
    int count=0;
    mtime las;
    for(int i=0;i<n;i++){
        if(i==0){
            las=sf[0];
            count++;
            continue;
        }
        if(las.f<=sf[i].s){
            las=sf[i];
            count++;
        }
    }
    cout<<count<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        mtime sf[n];
        for(int i=0;i<n;i++){
            cin>>sf[i].s;    
        }
        for(int i=0;i<n;i++){
            cin>>sf[i].f;    
        }
        sort(sf,sf+n,comparex);
        ifind(sf,n);
    }
	return 0;
}