//
// Created by sark2 on 04-08-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
class Graph{
    int V;
    list<int> *adj;
    bool util(int v, bool visited[], bool hstack[]);
public :
    Graph(int V):V(V){
    adj = new list<int>[V];
}
void addEdge(int u,int v){
    adj[u].push_back(v);

}
    bool isCycle();
};

bool Graph::util(int v, bool *visited, bool *hstack) {
    if(!visited[v]) {
        visited[v] = true;
        hstack[v] = true;

        for (auto i : adj[v]) {
            if (!visited[i]&& util(i, visited, hstack)) {
                    return true;
            }else if(hstack[i])return true;
        }
    }
    hstack[v] = false;
    return false;
}

bool  Graph::isCycle(){
    bool visited[V];
    bool hstack[V];
    memset(visited,false,sizeof visited);
    memset(hstack,false,sizeof hstack);
    for(int i = 0; i < V; i++){
        if(util(i,visited,hstack))
            return true;
    }
    return false;
}

int main() {
    IOS

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<<g.isCycle();


}
