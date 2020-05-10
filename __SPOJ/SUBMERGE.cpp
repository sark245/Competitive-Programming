//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);

const int N = 2e5 + 10;    
int n, m; //Number of Nodes, Edges
vi g[N];
vector<bool> vis;
vi tin, low;
int timer;
unordered_set<int> ap;

void dfs(int v, int p = -1){
    vis[v] = true;
    tin[v] = low[v] = timer++;

    int children = 0;

    for(int c : g[v]){
        if(c != p){
            if(vis[c])//Back Edge
                low[v] = min(low[v], tin[c]);
            else{
                //Tree Edge
                dfs(c, v);
                low[v] = min(low[v], low[c]);
                if(low[c] >= tin[v] and p != -1)
                    ap.insert(v);
                ++children;
            }
        }
    }

    if(p == -1 and children > 1)ap.insert(v);
}

void init(){
    timer = 0;
    
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i);
    }
}


int main(){
   IOS

    while(true){
        cin>>n>>m;
        if(n == 0 and m == 0)break;

        ap.clear();
        for(int i = 0; i< n; i++)g[i].clear();
        for(int i = 0; i < m ; i++){
            int u, v; cin>>u>>v;
            u--, v--;
            g[u].pb(v);
            g[v].pb(u);
        }

        init();

        cout<<ap.size()<<"\n";
    }


}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1)
        res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

