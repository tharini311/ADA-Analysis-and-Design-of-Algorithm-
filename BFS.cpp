#include<iostream>
#include<bits/stdc++.h>
 using namespace std;
 class BFS{
int V;
vector<list<int>>adj;
public:
    BFS(int V);
    void addedge(int v, int w);
    void solve(int s);
 };
 BFS:: BFS(int V){
    this->V=V;
    adj.resize(V);
 }
 void BFS::addedge(int v, int w){
    adj[v].push_back(w);
 }
 void BFS:: solve(int s){
    vector<bool> visited;
    visited.resize(V, false);
    list<int> queue;
    visited[s]=true;
    queue.push_back(s);
    while(!queue.empty()){
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(auto adjacent:adj[s]){
            if(!visited[adjacent]){
                visited[adjacent]=true;
                queue.push_back(adjacent);
            }
        }
    }
 }
 int main(){
    BFS g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,0);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,3);
    
    g.solve(2);
    return 0;
 }
    

 