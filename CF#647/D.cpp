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
    

const int N = 5e5 + 10;

vi g[N];

int main(){
   IOS

    int n, m; cin>>n>>m;

    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    map<int, set<int>> mp;

    for(int i = 1; i <= n; i++){
        int top;
        cin>>top;
        mp[top].insert(i);
    }

    bool poss = true;
    vi order;

    vi d(n + 1, -1);

    for(auto it : mp){
        for(auto j : it.second){
            d[j] = it.first;
            set<int> st;
            for(auto child : g[j]){
                if(d[child] != -1){
                    st.insert(d[child]);
                }
            }
            if(st.size() == d[j] - 1){
                if(st.size() > 0){
                    if(*st.rbegin() == d[j] - 1){

                    }else{
                        poss = false;
                        break;
                    }
                }

            }else poss = false;
            
            if(poss)order.pb(j);
            else break;
        }
        if(!poss)break;
    }

    if(!poss)cout<<"-1\n";
    else{
        for(auto it : order){
            cout<<it<<" ";
        }cout<<endl;
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

