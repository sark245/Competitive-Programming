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
       int n, m; cin>>n>>m;

       string s, r; cin>>s>>r;

       int dp[n+5][m+5];

       //dp[i][j] = min operations req to make s[1..i] and r[1..j] equal
       //dp[i][j] if equal chars : dp[i-1][j-1] ,   
       memset(dp, 0, sizeof dp);

       for(int i = 1; i <= n; i++){
           dp[i][0] = 1 + dp[i-1][0];
       }
       for(int j = 1; j <= m; j++){
           dp[0][j] = 1 + dp[0][j-1];
       }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == r[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i][j-1], dp[i-1][j]));
                }
            }
        }

        cout<<dp[n][m]<<"\n";

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

