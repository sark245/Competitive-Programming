//
// Created by sark2 on 30-12-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int INF = 1e9;

using pii = pair<int,int>;

vector<vector<pii>> adj;

void dijkstra(int s, vector<int>& d, vector<int>& p){
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n,-1);
    vector<bool>u(n,false);

    d[s] = 0;
    for(int i = 0; i < n; i++){
        int v = -1; //Search for the smallest vertex
        for(int j = 0; j < n; j++){
            if(!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if(d[v] == INF)
            break;

        u[v] = true;
        for(auto edge : adj[v]){
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}


//Set Based Implementation For Sparse Graphs

void dijkstra_set(int s, vector<int> & d, vector<int>& p){
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n,-1);
    
    d[s] = 0;
    set<pii> q;
    q.insert({0,s});
    
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        
        for(auto edge : adj[v]){
            int to = edge.first;
            int len = edge.second;
            
            if(d[v] + len < d[to]){
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}


vector<int> restore_path(int s, int t, vector<int>& p){
    vector<int> path;

    for(int v = t; v != s; v = p[v])
        path.pb(v);
    path.pb(s);

    reverse(path.begin(), path.end());
    return path;
}




int main() {
    IOS




}
