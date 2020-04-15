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

   string s;

   while(true){
       cin>>s;
       if(s == "0")break;

       int n = s.length();

       //dp[i] = number of encodings from 0 to i 
       // dp[i+next_two] += dp[i], dp[i+next_one] += dp[i]

       vector<ll> dp(n+5);

        int offset = 1;
       dp[-1 + offset] = 1;

       for(int i = -1; i < n-1; i++){
           if(s[i+1] == '0')continue;
           if(i <= n-2){
                dp[i+1+offset] += dp[i+offset];
           }
          
           if(i <= n-3){
               string ntwo = s.substr(i+1, 2);
               stringstream g(ntwo);
               int x = 0;
               g >> x;

               if(x <= 26)
                    dp[i+2+offset] += dp[i+offset];
           }
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

