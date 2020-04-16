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

        int a[n+5][n+5];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>a[i][j];
            }
        }

        int dp[n+5][n+5];
        for(int i = 0; i < n; i++){
            dp[0][i] = a[0][i];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n;j++){
                dp[i][j] = dp[i-1][j] + a[i][j];
                if(j-1 >= 0){
                    dp[i][j] = max(dp[i][j], a[i][j] + dp[i-1][j-1]);
                }
                if(j  <= n - 2){
                    dp[i][j] = max(dp[i][j], a[i][j] + dp[i-1][j+1]);
                }
            }
        }

        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, dp[n-1][i]);
        }

        cout<<mx<<"\n";
         

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

