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
       int n, k; cin>>n>>k;
 
       int last = k/ (n-1);
 
       int done = last  * (n-1);
 
       int rest = k - done;
 
        if(rest > 0)
            cout<<rest + last * n<<endl;
        else cout<<last * n - 1<<endl;
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
 
