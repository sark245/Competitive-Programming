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
    
const int N = 200;

int par[N];

void make_set(int v){
   par[v] = v;
}

int find_set(int v){
   if(v == par[v])return v;
   return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
   a = find_set(a);
   b = find_set(b);
   if(a != b){      
      par[b] = a;
   }
}


int main(){
   IOS

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
      

        vector<pii> v;
        for(int i = 0; i < n; i++){
            int a, b, c; cin>>a>>b>>c;
            v.pb({b, c});
        }

        for(int i = 0; i < N; i++){
            make_set(i);
        }

        sort(all(v), [](pii& p1, pii& p2)->bool{
            return p2.second < p1.second;
        });

        int ans = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            int av = find_set(v[i].first);
            //cout<<v[i].first<<" "<<v[i].second<<" "<<av<<"\n";
            if(av > 0){
                union_set(av - 1, av);
                ans += v[i].second;
                cnt++;
            }
        }

        cout<<cnt<<' '<<ans<<'\n';
      
    }
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

