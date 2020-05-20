//Prim's MST

/*
Given a weighted, undirected and connected graph. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

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



int spanningTree(int V,int E,vector<vector<int> > graph)
{
    int visit[V];
    int minval[V];
    int cnt=0;
    
    for(int i=0;i<V;i++){
        visit[i]=-1;
        minval[i]=INT_MAX;
    }
    
    minval[0]=0;
    int cc=V;
    while(cc--){
        int min=INT_MAX,ind;
        for(int i=0;i<V;i++){
            if(visit[i]==-1&&minval[i]<min){
                ind=i;
                min=minval[i];
            }
        }
        
        visit[ind]=0;
        cnt+=minval[ind];
        
        for(int i=0;i<V;i++){
            if(graph[ind][i]<minval[i]&&visit[i]==-1){
                minval[i]=graph[ind][i];
            }
        }
    }
    
    return cnt;
}
