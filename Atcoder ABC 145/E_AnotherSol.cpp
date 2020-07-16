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

    int n, t; cin>>n>>t;

    int dp[n + 1][t + 1];

    memset(dp, 0, sizeof dp);

    vi a(n), b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i];
    }

    for(int i = a[0]; i <= t; i++){    
        dp[0][i] = max(dp[0][i], dp[0][i-a[i]] + b[i]);
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= t; j++){
            dp[i][j] = dp[i-1][j];
            if(j - a[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
            }
        }
    }

    cout<<dp[n-1][t]<<"\n";
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

