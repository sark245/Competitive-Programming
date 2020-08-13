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

const int N = 110;
int n, p[N], g[N][N], ans[N];
bool vis[N];
pii v[N];
vi comp, x;
void dfs(int node){
    vis[node] = true;
    for(int i = 1; i <= n; i++){
        if(i != node){
            if(g[node][i] && !vis[i]){
                comp.pb(i);
                x.pb(v[i].second);
                dfs(i);
            }
        }
    }
}


void solve(){
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>p[i];
        v[i] = {i, p[i]};
    }

  

    memset(vis, false, sizeof vis);

    //graph is based on index not on Pi
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin>>c;
            if(c == 'Y')g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    //O(n^3logn)
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            comp.clear();
            x.clear();
            comp.pb(i);
            x.pb(v[i].second);
            dfs(i);
            sort(all(x));
            sort(all(comp));

            for(int j = 0; j < comp.size(); j++){
                ans[comp[j]] = x[j];
            }
        }
    }


    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }

    
}


int main(){
   IOS

    solve();

}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1) res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

