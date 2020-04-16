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

       vi a(n); ;
       for(int & x: a)cin>>x;

        //dp[i][j]-> dp[i+1][j]-> dp[i+2][j], dp[i+1][j-1], dp[i][j-1] -> dp[i+1][j], dp[i][j-2]

        int dp[n+5][n+5];

        memset(dp, 0, sizeof dp);

        for(int i = 0; i < n; i++){
            dp[i][i] = a[i];
        }

        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n-l+1; i++){
                int j = i + l-1;
                int something = min(dp[i+2][j], dp[i+1][j-1]);
                int something_else = min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] = max(a[i] + something, a[j] + something_else);
            }
        }

        cout<<dp[0][n-1]<<"\n";
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

