#include<iostream>
#include<climits>
using namespace std;
#define INF INT_MAX
#define V 4

 void floyd(int graph[V][V]){
    int reach[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            reach[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
             if(reach[i][k]!= INF && reach[k][j]!=INF && reach[i][k]+reach[k][j]<reach[i][j]){
                reach[i][j]=reach[i][k]+reach[k][j];
             }
            }
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(reach[i][j]==INF){
                cout<<"inf";
            }
            else cout<<reach[i][j]<<" ";
        }
        cout<<endl;
    }
 }
  int main(){
    int graph[V][V]={{0,INF,3,INF},{2,0,INF,INF},{INF,7,0,1},{6,INF,INF,0}};
    floyd(graph);

  }