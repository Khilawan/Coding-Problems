/*
You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. Your task is to complete the function maxChainLen which returns an integer denoting the longest chain which can be formed from a given set of pairs. 

Example(To be used only for expected output):
Input
2
5
5 24 39 60 15 28 27 40 50 90
2
5 10 1 11 
Output
3
1
*/

#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}


bool comparex(struct val a,struct val b){
    return (a.second<b.second);
}

int maxChainLen(struct val p[],int n)
{
    int count=1;
    sort(p,p+n,comparex);
    int prev=p[0].second;
    for(int i=1;i<n;i++){
        if(prev<p[i].first){
            count++;
            prev=p[i].second;
        }
    }
    return count;
}