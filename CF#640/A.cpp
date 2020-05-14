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
 
       int temp = n, ans = 0;
       vi a;
       int i = 0;
       while(temp){
           if(temp % 10 != 0)
            ans++, a.pb(temp%10 * pow(10, i));
           temp /= 10;
           i++;
       }
 
 
       cout<<ans<<"\n";
 
       for(auto it : a)cout<<it<<" ";
 
       cout<<endl;
 
 
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
