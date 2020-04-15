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
    



int main(){
   IOS

    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;

        vi p(k+1); 
        int s = k*k;
        for(int i = 1; i <= k; i++)cin>>p[i];

        vi dp(s+5, 1e9);
        dp[0] = 0; 
       for(int cwt = 0;cwt <= s; cwt++){
           for(int i = 1; i <= k; i++){
               if(p[i] == -1)continue;
               if(cwt + i <= s)
                    dp[cwt + i] = min(dp[cwt+i], dp[cwt]+p[i]);
           }
       }

       cout<<(dp[k] >= 1e9 ? -1: dp[k])<<"\n";



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

