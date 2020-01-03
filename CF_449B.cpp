//https://codeforces.com/problemset/problem/449/B#


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
const int N = 1e5+10;

using pii = pair<int,int> ;
using pli = pair<ll, int> ;
const ll INF = LLONG_MAX;
ll c[N], d[N];

vector<pli> adj[N];


int main() {
    IOS

    int n, m, k;
    cin>>n>>m>>k;

    for(int i = 0; i < n; i++){
        c[i] = d[i] = INF;
    }
    d[0] = 0ll;

    for(int i = 0; i < m; i++){
        int u, v, x;
        cin>>u>>v>>x;
        u--,v--;
        adj[u].pb({x,v});
        adj[v].pb({x,u});
    }

    for(int i = 0; i < k; i++){
        int x; ll z;
        cin>>x>>z;
        x--;
        c[x] = min(c[x], z);
    }


    set<pli> q;

    for(int i = 0; i < n; i++){
        q.insert({d[i], i});
        if(c[i] != INF)
            q.insert({c[i], i});
    }

    int ans = k;

    while(!q.empty()){
        int v = q.begin()->second;
        ll z = q.begin()->first;
        q.erase(q.begin());

        if(z < d[v])
            ans--;

        d[v] = min(d[v], z);
        for(auto edge : adj[v]){
            int to = edge.second;
            ll len = edge.first;

            if(d[v] + len < d[to]){
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }

    cout<<ans<<"\n";
}
