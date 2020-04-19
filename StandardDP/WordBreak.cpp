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
       unordered_set<string> st;
       for(int i = 0; i < n; i++){
           string s; cin>>s;
           st.insert(s);
       }

       string s; cin>>s;

       int m = s.length();

       vector<bool> dp(m+1);


       for(int i = 0; i < m; i++){
           if(!dp[i] and st.count(s.substr(0, i+1)))
                dp[i] = true;
            if(dp[i]){
                for(int j = i + 1; j < m; j++){
                    if(!dp[j] and st.count(s.substr(i+1,j-i)))
                        dp[j] = true;
                }
            }
       }
       cout<<dp[m-1]<<"\n";
       
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

