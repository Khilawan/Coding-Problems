/*
Given a graph of V nodes represented in the form of the adjacency matrix. 
The task is to find the shortest distance of all the vertex's from the source vertex.

Example:
Input:
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output:
0 25
7 6 0
*/

#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );


int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}


void dijkstra(vector<vector<int>> graph, int src, int V)
{             
    int visited[V];
    int minpathval[V];
    
    for(int i=0;i<V;i++){
        visited[i]=-1;
        minpathval[i]=INT_MAX;
    }
    
    minpathval[src]=0;
    int itenum=V;
    
    while(itenum--){
        int min=INT_MAX,ind;
        for(int i=0;i<V;i++){
            if(visited[i]==-1&&minpathval[i]<min){
                min=minpathval[i];
                ind=i;
            }
        }
        
        visited[ind]=0;
        
        for(int i=0;i<V;i++){
            if(graph[ind][i]!=0&&minpathval[i]>(minpathval[ind]+graph[ind][i])&&visited[i]==-1){
                minpathval[i]=minpathval[ind]+graph[ind][i];
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<minpathval[i]<<" ";
    }
}
