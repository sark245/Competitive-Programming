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
       int n, W; cin>>n>>W;

       vi wt(n), v(n);
        for(int &x : v)cin>>x;
       for(int &x : wt)cin>>x;

        vi dp(W+1);
        
        if(wt[0] <= W)
            dp[wt[0]] = v[0];

        for(int i = 1; i < n; i++){
            vi new_dp(W+1); 
            new_dp = dp;
            for(int w = 0; w <= W; w++){
                if(w-wt[i] >= 0){
                    new_dp[w] = max(new_dp[w], v[i] + dp[w-wt[i]]);
                }
            }
            dp = new_dp;
        }


        int mx = 0;
        for(int w = 0; w <= W; w++){
            mx = max(dp[w], mx);
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

