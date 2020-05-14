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
	   int n0, n1, n2; cin>>n0>>n1>>n2;
	   string s;
	   
	   if(n0 > 0){
		   s = string(n0 + 1, '0');
	   }
 
	   if(n0 == 0 and n1 > 0)s = '0';
 
	   for(int i = 1; i <= n1; i++){
		   if(i == 1){
			   s = string(1, '1') + s;
		   }
		   else{
			   if(i & 1){
				   s += string(1, '0');
			   }else{
				   s += string(1, '1');
			   }
		   }
	   }
 
	   if(n2 > 0){
		   if(n1 >= 1)
		   		s = string(n2, '1') + s;
			else s = string(n2 + 1, '1') + s;
	   }
 
	   cout<<s<<endl;
 
 
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
 
