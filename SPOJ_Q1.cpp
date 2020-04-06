//https://www.spoj.com/problems/SUMPRO/

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
       ll n; cin>>n;
        ll i;
       ll ans = 0, right_end, left_end;
       

       for(i = 1; i <= sqrt(n); i++){
            right_end = n / i;
            left_end = n / (i + 1);
            ans = (ans + i * (((right_end*(right_end+1))/2) - ((left_end*(left_end+1))/2))) % mod;
       }

        ll last = n/i;
      
      for(i = 1; i <= last; i++)
        ans = (ans + i * (n / i))%mod;

        cout<<ans<<"\n"; 
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

