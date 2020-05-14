/*
There is one meeting room in a firm.
There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

Example:
Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252

Output:
1 2 4 5
6 7 1
*/

#include<bits/stdc++.h>
using namespace std;

struct mtime{
    long s;
    long f;
    long ind;
};

bool comparex(mtime a,mtime b){
    return (a.f<b.f);
}

void ifind(mtime sf[],int n){
    mtime k;
    for(int i=0;i<n;i++){
        if(i==0){
            k=sf[i];
            cout<<sf[i].ind<<" ";
            continue;
        }
        if(k.f<=sf[i].s){
            k=sf[i];
            cout<<sf[i].ind<<" ";
        }
    }
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
            sf[i].ind=i+1;
        }
        for(int i=0;i<n;i++){
            cin>>sf[i].f;
        }
        sort(sf,sf+n,comparex);
        ifind(sf,n);
        cout<<endl;
    }
	return 0;
}
