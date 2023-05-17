#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define V 9


void relax(int u,int graph[][V],int dist[],bool visited[],int par[]){
    
    for(int v=0;v<V;v++){
        if(graph[u][v] && dist[v]>dist[u]+graph[u][v])
            {   dist[v]=dist[u]+graph[u][v];
                par[v]=u;
            }
    }
    
}
    
    
void initializeSingleSource(int dist[],int source,int par[],bool visited[])
    {
        
        for(int i=0;i<V;i++){
            
            dist[i]=INT_MAX;
            par[i]=-1;
            visited[i]=false;
            
        }
        dist[source]=0;
        
        
    }
int min_Dist(int dist[],bool visited[]){
    int min=INT_MAX;
    
    int min_index;
    for(int v=0;v<V;v++){
        if(dist[v]<=min && visited[v]==false){
            min=dist[v];
            min_index=v;
        }
        
    }
    return min_index;
}
    
void djikstra(int graph[][V],int dist[],bool visited[],int par[]){
        int u;
        for(int count=0;count<V-1;count++){
            u=min_Dist(dist,visited);   
        
        relax(u,graph,dist,visited,par);
        visited[u]=true;
        }
    }



int main () {
    int graph[V][V] = { { 0, 11, 0, 0, 0, 0, 0, 8, 0 },
                { 11, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
                };
    int source=0;
    int dist[V], par[V];
    bool visited[V];
    initializeSingleSource(dist,source,par,visited);
    
    djikstra(graph,dist,visited,par);
   

    
    printf("Vertex\tDist\tParent\n");
    for(int i=0; i<V; i++)
        printf("%d\t\t%d\t\t%d\n", i, dist[i], par[i]);
   
}

    
    
