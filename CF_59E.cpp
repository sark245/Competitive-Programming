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
const int N = 3001;

using pii = pair<int,int>;
const int INF = INT_MAX;



pii pr[N][N];
vector<int> adj[N];

int main() {
    IOS


    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            pr[i][j] = {-1,-1};
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

   set<pair<pii, int> > bad;

    for(int i = 0; i < k; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--, c--;
        bad.insert({{a,b},c});
    }

    pr[0][0] = {-2, -2};
    queue<pii> q;

    q.push({0,0});

    pii last = {-1, -1};

    while(!q.empty()){
        auto p = q.front();
        if(p.second == n-1){
            last = p;
            break;
        }

         q.pop();

         for(int v : adj[p.second]){
             if(!bad.count({p,v}) && pr[p.second][v] == make_pair(-1,-1)){
                 pr[p.second][v] = p;
                q.push({p.second, v});
            }
        }
    }

    if(last == make_pair(-1,-1)){
        cout<<-1<<"\n";
        return 0;
    }
    vector<int> ans;

    while(last != make_pair(-2, -2)){
        ans.pb({last.second});
        last = pr[last.first][last.second];
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()-1<<"\n";

    for(auto v : ans){
        cout<<v+1<<" ";
    }
    return 0;

}
