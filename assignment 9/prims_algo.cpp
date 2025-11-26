#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
using AdjList=vector <vector< pair<int,int>> >;

void add_edge(AdjList &adj,int u,int v,int wt){
    adj[u].push_back({wt,v});
    adj[v].push_back({wt,u});    
}
AdjList buildadjlist(int V,int E){
    AdjList adj(V+1);
    for(int i=0;i<E;i++){
        int u,v,wt;
        cout<<"Edge "<<i+1<<"(u,v,wt): ";
        cin>>u>>v>>wt;
        add_edge(adj,u,v,wt);
        cout<<endl;
    }
    return adj;
}

int primsMST(int V,AdjList adj){ //V->no. of vertices i.e nodes
    //syntax: priority_queue < datatype, container, comparator> //comparator is by default less i.e max heap but we want min heap for MST
    priority_queue < pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq; // by default first elem of pair is used for comparison
    //PQ: {weight,node}
    vector <int> vis(V,0);
    int sum=0;

    pq.push({0,0});
    
    while(!pq.empty()){
        auto elem=pq.top(); //can also use auto datatype to let it decide for itself
        pq.pop();
        int wt=elem.first;
        int node=elem.second;
        if(vis[node]) continue; //if already visited then skip to end 
        //when unvisited: add to MST 
        vis[node]=1;
        sum+=wt;
        //cout<<"node: "<<node<<" weight: "<<wt<<endl;
        //cout<<"sum: "<<sum<<endl;

        //find all the adjacent nodes (i.e nodes connected to current node)
        for(auto nbr:adj[node]){
            int adjnode=nbr.second;
            int edgewt=nbr.first;
            if(!vis[adjnode]){
                pq.push({edgewt,adjnode});
            }
        }
    }
    return sum;
}

int main() {
    int V=5;
    int E=6;
   
    AdjList adj_list=buildadjlist(V,E);
    int mst_sum=primsMST(V,adj_list);
    cout<<"the minimum spanning cost is "<<mst_sum<<endl;
	return 0;
}
