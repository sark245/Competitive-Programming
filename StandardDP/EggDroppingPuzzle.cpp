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

        int dp[n+5][k+5];
        memset(dp, 0, sizeof dp);

        for(int i = 1; i <= k; i++){
            dp[1][i] = i;
        }

        for(int i = 1; i <= n; i++){
            dp[i][1] = 1;
        }

        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= k; j++){
                dp[i][j] = 1e9;
                for(int c = j; c >= 1; c--){
                    dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][c-1], dp[i][j-c]));
                }
            }
        }

        cout<<dp[n][k]<<"\n";
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

