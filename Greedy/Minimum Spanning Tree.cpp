//Kruskal's MST

/*
Given a weighted, undirected and connected graph.
The task is to find the sum of weights of  the edges of the Minimum Spanning Tree.

Example:
Input:
2
3 3
1 2 5 2 3 3 1 3 1
2 1
1 2 5

Output:
4
5
*/

#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,int E,vector<vector<int> > graph);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));

        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}

#define pi pair<int,pair<int,int>>

int ifind(int parent[],int i){
    if(parent[i]==-1){
        return i;
    }
    return ifind(parent,parent[i]);
}

void iunion(int parent[],int x,int y){
    int xp=ifind(parent,x);
    int yp=ifind(parent,y);
    if(xp!=yp){
        parent[xp]=yp;
    }
}


int spanningTree(int V,int E,vector<vector<int> > graph)
{
    priority_queue<pi, vector<pi>, greater<pi>>pq;
    for(int i=0;i<graph.size();i++){
        for(int j=i;j<graph[i].size();j++){
            pair<int,int>pp;
            pp.first=i;
            pp.second=j;
            int val=graph[i][j];
            pi p2;
            p2.first=val;
            p2.second=pp;
            if(val!=INT_MAX){
                pq.push(p2);
            }
        }
    }
    int parent[V];
    memset(parent,-1,sizeof(int)*V);
    int cnt=0;
    while(!pq.empty()){
        pi p1=pq.top();
        pq.pop();
        int wt=p1.first;
        int x=p1.second.first;
        int y=p1.second.second;
        if(ifind(parent,x)!=ifind(parent,y)){
            cnt+=wt;
            iunion(parent,x,y);
        }
    }
    return cnt;
}
