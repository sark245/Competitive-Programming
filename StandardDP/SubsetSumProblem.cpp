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

       vi a(n); int S = 0;
       for(int & x: a)cin>>x, S += x;

       if(S&1)cout<<"NO\n";
       else{
           bool dp[n+1][S+5];

           memset(dp, false, sizeof dp);

           for(int i = 0; i <= n; i++)dp[i][0] = true;

           for(int i = 1; i <= n; i++){
               for(int s = 0; s <= S; s++){
                   dp[i][s] |= dp[i-1][s];
                    if(s - a[i-1] >= 0){
                        dp[i][s] |= dp[i-1][s - a[i-1]];
                    }
               }
           }

           if(dp[n-1][S/2])cout<<"YES\n";
           else cout<<"NO\n";
       }

       

         

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

