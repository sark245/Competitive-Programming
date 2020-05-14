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
        unordered_map<int, int> mp;
       vi a(n);
       for(int & x : a)cin>>x, mp[x]++;
 
        vi pre(n);
        pre[0] = a[0];
 
        int ans = 0;
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + a[i];
        }
 
        unordered_set<int> st;
 
        for (int l = 2; l <= n; l++){
            if(mp.count(pre[l-1]) and !st.count(pre[l-1]))ans += mp[pre[l-1]], st.insert(pre[l-1]);
            for(int i = l; i < n; i++){
                if(mp.count(pre[i] - pre[i-l]) and !st.count(pre[i] - pre[i-l]))
                    ans += mp[pre[i] - pre[i-l]], st.insert(pre[i] - pre[i-l]);
            }
        }
 
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
 
