#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void util(int v, bool visited[], stack<int>& st);
public :
    Graph(int V);
    void addEdge(int u,int v);
    string Tsort();

};

Graph::Graph(int  V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::util(int v, bool visited[], stack<int>& st){
    visited[v] = true;
    for(auto i : adj[v]){
        if(!visited[i])
            util(i,visited,st);
    }
    st.push(v);
}
string Graph::Tsort(){
    stack<int>st;
    bool *visited = new bool[V];
    memset(visited, false, V);

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            util(i,visited,st);
        }
    }

    string res = "";
    while(!st.empty()){
        res += ('a'+st.top());
        st.pop();
    }
    return res;
}

string printOrder(string dict[], int N, int k)
{
    Graph g(k);
    for(int i = 0; i < N-1; i++){
        string w1 = dict[i], w2 = dict[i+1];
        for(int i = 0; i < min(w1.length(),w2.length()); i++){
            if(w1[i] != w2[i]){
                g.addEdge(w1[i]-'a',w2[i]-'a');
                break;
            }
        }
    }

    string res = g.Tsort();
    return res;

}

int main(){

}