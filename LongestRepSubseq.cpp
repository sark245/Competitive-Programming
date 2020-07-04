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
      string s; cin>>s;

      int dp[n + 1][n + 1];
      memset(dp, 0, sizeof dp);

     

      for(int i = 1; i <= n; i++){
         for(int j = 1; j <= n; j++){
            if(s[i - 1] == s[j - 1] && i != j){
               dp[i][j] = 1 + dp[i-1][j-1];
            }else{
               dp[i][j] =max(dp[i][j-1], dp[i-1][j]);
            }
         }
      }

      cout<<dp[n][n]<<"\n";
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

