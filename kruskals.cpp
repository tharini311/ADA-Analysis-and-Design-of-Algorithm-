
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DSU{
     int * rank; int *parent;
     public: 
      DSU(int n){
        parent= new int[n];
        rank= new int[n];
         for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
         }
      }
      int find(int i){
        if(parent[i]==-1)
         return i;
        return parent[i]=find(parent[i]);
      }
       void unite(int x, int y){
         int s1=find(x);
         int s2=find(y);
         if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
            }
             else if(rank[s1]>rank[s2]){
                parent[s2]=s1;
             }
             else{
                parent[s2]=s1;
                rank[s1]+=1;
             }
         }
       }
};
class graph{
 vector<vector<int>>edgelist;
 int v;
 public: graph(int v){
    this->v=v;
 }
  void addEdge(int x,int y,int w){
     edgelist.push_back({w,x,y});
  }
  void krushal_mst(){
     int ans=0;
    sort(edgelist.begin(),edgelist.end());
    DSU s(v);
    cout<<"following shows the edge ";
    for(auto edge:edgelist){
        int w=edge[0];
        int x=edge[1];
        int y=edge[2];
        if(s.find(x)!=s.find(y)){
            s.unite(x,y);
            ans+=w;
            cout<<x<<"--"<<y<<"="<<w<<flush<<endl;
        }

    }
    cout<<"mst :"<<ans;
  }
};
 int main(){
    graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);
    g.addEdge(2,0,6);
    g.addEdge(0,3,5);
   g.krushal_mst();
   return 0;


 }