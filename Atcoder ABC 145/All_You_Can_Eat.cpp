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

   int n, T;
   cin>>n>>T;

   vector<pii> a(n);
   for(int i = 0; i < n; i++){
      cin>>a[i].first>>a[i].second;
   }
   sort(all(a));

   vi dp((int)1e4);

   
   for(int i = 0; i < n; i++){
      for(int time = T - 1; time >= 0; time--){
         int A = a[i].first;
         int B = a[i].second;
         dp[time + A] = max(dp[time + A], dp[time] + B);
      }
   }

   int mx = 0;
   for(int v : dp){
      mx = max(mx, v);
   }

   cout<<mx<<"\n";
   

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

