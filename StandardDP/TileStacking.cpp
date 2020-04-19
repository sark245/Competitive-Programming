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

   int n, m, k; cin>>n>>m>>k;

   int dp[n+5][m+5]; memset(dp, 0, sizeof dp);

   //dp[i][m-1]   for i from 0 to n

   for(int i = 0; i <= k; i++){
       dp[i][m] = 1;
   }

   for(int i = 1; i <= m; i++){
       dp[0][i] = 1;
   }

   for(int j = m-1; j >= 1; --j){
       for(int i = n; i >= 1; --i){
           for(int x = 0; x <= k; x++){
               if(i-x >= 0)
               dp[i][j] += dp[i-x][j+1];
           }
       }
   }

   cout<<dp[n][1]<<"\n";


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

