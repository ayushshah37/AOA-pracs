#include <stdio.h>
#include<stdbool.h>
int graph[100][100],colors[100],num_vertices,num_colors,num_edges;
bool used_colors[100];


int get_available_color(int vertex,int num_colors){
    for(int i=0;i<num_colors;i++){
        used_colors[i]=false;
        
    }
    for(int i=0;i<num_vertices;i++){
        if(graph[vertex][i]  && colors[i]!=-1){
            used_colors[colors[i]]=true;
        }
        
        
    }
    for(int i=0;i<num_colors;i++){
        if(used_colors[i]==false){
            return i;
        }
        
    }
    return -1;
}




int main()
{
    printf("enter the no. of vertices:");
    scanf("%d",&num_vertices);
    printf("enter the number of edges:");
    scanf("%d",&num_edges);
    printf("enter number of colors:");
    scanf("%d",&num_colors);
    
    for(int i=0;i<num_edges;i++){
        int u ,v;
        printf("%d is between 2 vertices :",i);
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;
    }
    
    for(int i=0;i<num_vertices;i++){
        colors[i]=-1;
    }
    for(int i=0;i<num_vertices;i++){
        colors[i]=get_available_color(i,num_colors);
    }
    printf("coloring:\n");
    for(int i=0;i<num_vertices;i++){
        printf("vetrex:%d  color:%d \n",i,colors[i]);
    }
    
    return 0;
}


