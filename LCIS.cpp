//Created by Kira
//Longest Common Increasing Subsequence
/*
TestCase
1
29
6 21 37 45 27 23 66 9 17 83 59 25 38 63 25 1 37 53 100 80 51 69 72 74 32 82 31 34 95
11
64 100 82 100 97 60 74 14 69 91 96
*/


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
      int n, m; cin>>n;

      vi a(n);
      for(int &x : a)cin>>x;

      cin>>m;
      vi b(m);
      for(int &x :b)cin>>x;

      int dp[m];  //dp[i] = length of LCIS ending at b[i]
      //for every element in a[], traverse b[], 
      // If we find that a[i] and b[j] are equal, 
      // then just update(check) val for dp[j]
      //otherwise if you see a smaller element in b[], then compare current value against it 
      //and update accordingly.!!!!
      memset(dp, 0, sizeof dp);

      for(int i = 0; i < n; i++){
         int cur = 0;
         for(int j = 0; j < m; j++){
            if(a[i] == b[j]){
               dp[j] = max(dp[j], cur + 1);
            }
            if(a[i] > b[j]){
               cur = max(cur, dp[j]);
            }
         }
      }
      int ans = 0;
      for(int i = 0; i < m; i++){
         if(dp[i] > ans)
            ans = dp[i];
      }
      cout<<ans<<"\n";
   }
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

