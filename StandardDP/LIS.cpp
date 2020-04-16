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

       vi dp(n, 1);

       for(int i = 1; i < n; i++){
           for(int j = i-1; j >= 0; j--){
               if(a[j] < a[i])dp[i] = max(dp[i], 1 + dp[j]);
           }
       }
        int mx = 0;
       for(int i = 0; i < n; i++){
           mx = max(mx, dp[i]);
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

