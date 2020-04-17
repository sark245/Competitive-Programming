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
       string s; cin>>s;

       pair<int,int> dp[n+5][n+5];

       for(int i = 0; i < n; i++){
           for(int j = 0; j < n; j++){
               if(i == j){
                   if(s[i] == 'T'){
                       dp[i][i] = {1, 0};
                   }else dp[i][i] = {0,1};
               }else
               dp[i][j] = {0,0};
           }
       }

       for(int l = 3; l <= n; l+= 2){
           for(int i = 0; i < n-l+1; i += 2){
               int j = i + l - 1;

               ll tv = 0, fv = 0;

               for(int k = i; k <= j; k += 2){
                   //[i...k] [k+2 ... j]
                   if(s[k+1] == '^'){
                       tv += dp[i][k].first*dp[k+2][j].second + dp[i][k].second*dp[k+2][j].first;
                       fv += dp[i][k].first*dp[k+2][j].first + dp[i][k].second * dp[k+2][j].second;
                   }
                   else if(s[k+1] == '&'){
                       tv += dp[i][k].first*dp[k+2][j].first;
                       fv += dp[i][k].second*dp[k+2][j].second + dp[i][k].second*dp[k+2][j].first + dp[i][k].first*dp[k+2][j].second;
                   }else if(s[k+1] =='|'){
                       tv += dp[i][k].first*dp[k+2][j].first + dp[i][k].second*dp[k+2][j].first + dp[i][k].first*dp[k+2][j].second;
                       fv += dp[i][k].second*dp[k+2][j].second;                       
                   }

                   tv %= 1003, fv %= 1003;
               }

               dp[i][j] = {tv, fv};

           }
       }
       cout<<dp[0][n-1].first<<"\n";       
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

