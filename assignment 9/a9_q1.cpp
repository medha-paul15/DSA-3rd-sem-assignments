#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph{
    int V; //V is number of vertices 
    list<int> *l;

    public:
        Graph(int n){
            this->V=n; 
            l=new list<int> [V];
        }
        
        void addEdge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void printAdjList(){
            for(int i=0;i<V;i++){
                cout<<i<<": ";
                for(int nbr:l[i]){
                    cout<<nbr<<" ";
                }
                cout<<endl;
            }
        }
        void bfs(int start=0){
            cout<<"\nBFS traversal: ";
            queue <int> Q;
            vector <bool> vis(V,false);
            Q.push(start);
            vis[start]=true;

            while(Q.size()>0){
                int u=Q.front(); //u is source, v is destination/neighbour
                Q.pop();
                cout<<u<<" ";
                for(int v: l[u]){ //l[u] contains the neighbours of u 
                    if(!vis[v]){
                        vis[v]=true;
                        Q.push(v);
                    }
                }
            }
            cout<<endl;
        }

        void dfsHelper(int u, vector <bool> &vis){
            cout<<u<<" ";
            vis[u]=true;

            for(int v:l[u]){
                if(!vis[v]){
                    dfsHelper(v,vis);
                }
            }
        }
        void dfs(){
            cout<<"DFS traversal: ";
            int src=0;
            vector <bool>vis(V,false);
            dfsHelper(src,vis);
        }
};
vector <vector<int>> buildAdjMatrix(int V,int E){
    int u, v;
	// declare the Adjacency matrix 
       vector<vector<int>> adj(V + 1, vector<int>(V + 1, 0));

	// take edges as input 
	for (int i = 0; i < E; i++) {
        cout<<"edge: ";
		cin >> u >> v;
        int w;
        cout<<"\tweight: "; cin>>w;
		adj[u][v] = w;
		adj[v][u] = w;
    }
    return adj;
}

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.printAdjList();
    g.bfs(2);
    g.dfs();
}
