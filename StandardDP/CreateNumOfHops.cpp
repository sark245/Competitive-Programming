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
       int n; cin>>n;

       int dp[n+5];
       memset(dp, 0, sizeof dp);

       dp[1] = 1, dp[2] = 2, dp[3] = 4;

       for(int i = 4; i <= n; i++){
           dp[i] += dp[i-1] + dp[i-2] + dp[i-3];
       } 

       cout<<dp[n]<<"\n";
         

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

