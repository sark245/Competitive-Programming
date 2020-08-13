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

const ll INF = 1e15;

ll dis[26][26];

void solve(){
    string s; cin>>s;
    int m; cin>>m;

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }

    for(int i = 1; i <= m; i++){
        ll c;
        char x, y; cin>>x>>y>>c;
        dis[x - 'a'][y - 'a'] = c;
        dis[y - 'a'][x - 'a'] = c;
    }

    for(int k = 0; k < 26; k++){
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(dis[i][k] < INF && dis[k][j] < INF){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    ll ans = 0;
    int n = sz(s);
    for(int i = 0; i < n/2; i++){
        ll mi = INF;
        for(char c = 'a'; c <= 'z'; c++){
            mi = min(dis[c - 'a'][s[i] - 'a'] + dis[c - 'a'][s[n - 1 - i] - 'a'], mi);
        }
        ans += mi;
    }
    cout<<ans<<'\n';
    
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

