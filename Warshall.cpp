#include<iostream>
using namespace std;
#define V 4
 void Transitive_closure(int graph[V][V]){
    int reach[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            reach[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
             reach[i][j]=reach[i][j]|| reach[i][k]&&reach[k][j];
            }
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<reach[i][j]<<" ";
        }
        cout<<"\n";
    }
 }
  int main(){
    int graph[V][V]={{0,1,0,0},{0,0,1,0},{1,0,0,1},{0,0,0,0}};
    Transitive_closure(graph);

  }