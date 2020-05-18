/*
Given arrival and departure times of all trains that reach a railway station. 
Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. 
Also, arrival and departure times will not be same for a train, 
but we can have arrival time of one train equal to departure of the other. 
In such cases, we need different platforms, i.e at any given instance of time, 
same platform can not be used for both departure of a train and arrival of another.

Example:
Input:
2
6 
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240 

Output:
3
1
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        multimap<int,int>m;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            m.insert(pair<int,int>(num,1));
        }
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            m.insert(pair<int,int>(num,-1));
        }
        int count=0,max=0;
        multimap <int, int> :: iterator it;
        for(it=m.begin();it!=m.end();it++){
            count+=it->second;
            if(max<count){
                max=count;
            }
        }
        cout<<max<<endl;
    }
}
