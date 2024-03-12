#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Dfs{
    public:
     map<int , bool> visited;
     map<int , list<int>> adj;
     void addedge(int v, int w);
    void solve(int v);
};
 void Dfs:: addedge(int v, int w){
adj[v].push_back(w);
 }
  void Dfs:: solve(int v){
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator i;
   for(i=adj[v].begin();i!=adj[v].end();i++){
       if(!visited[*i]){
        solve(*i);
       }
   }

  }
  int main(){
    Dfs g;
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    g.solve(2);
    return 0;
  }