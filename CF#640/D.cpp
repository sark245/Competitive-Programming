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
 
	   int i = 0, j = n-1, ac = 0, bc = 0, moves = 0, lb = 0, la = 0;
 
	   while(true){
		   int t1 = lb + 1;
		   lb = 0;
		   while(t1 > 0 and i <= j){
			   t1 -= a[i];
			   ac += a[i];
			   la += a[i];
			   i++;
		   }
 
		   moves++;
 
		   if(i > j)break;
 
		   int t2 = la + 1;
		   la = 0;
 
		   while(t2 > 0 and j >= i){
			   t2 -= a[j];
			   bc += a[j];
			   lb += a[j];
			   j--;
		   }
		   moves++;
 
		   if(j < i)break;
	   }
 
	   cout<<moves<<" "<<ac<<" "<<bc<<"\n";
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
 
