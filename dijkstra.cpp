#include<iostream>
using namespace std;
#include<limits.h>
#define V 9
int mindis(int dist[], bool mstset[]){
    int min=INT_MAX, min_index;
    for(int i=0;i<V;i++){
        if(mstset[i]==false&& dist[i]<min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
 void print(int dist[]){
    for(int i=0;i<V;i++){
         cout<<i<<"-"<<dist[i]<<endl;
    }
 }
 void dijstra(int graph[V][V],int s){
int dist[V];
bool mstset[V];
for(int i=0;i<V;i++){
    dist[i]=INT_MAX;
    mstset[i]=false;
}
dist[0]=0;
for(int count=0;count<V-1;count++){
    int u=mindis(dist, mstset);
    mstset[u]=true;
    for(int v=0;v<V;v++){
        if(graph[u][v]&& mstset[v]==false&& dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v] ){
            dist[v]=dist[u]+graph[u][v];
        }
    }
    }
 print(dist);
 } 
 int main(){
     int graph[V][V]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
     dijstra(graph, 0);
 }