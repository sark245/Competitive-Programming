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
       vi a(n);
       for(int & x : a)cin>>x;
        int tar; cin>>tar;

        vi dp(tar + 1, 0);

        dp[0] = 1;

        for(int i = 0; i < n; i++){
            for(int c = 0; c <= tar; c++){
                if(c + a[i] <= tar)
                    dp[c + a[i]] += dp[c];
            }
        }
        
        cout<<dp[tar]<<"\n";
       
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

