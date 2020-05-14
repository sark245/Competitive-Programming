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
 
		if(n < 4){
			cout<<-1<<"\n";
			continue;
		}
 
		for(int i = 2; i <= n; i += 2){
			cout<<i<<" ";
		}
 
		int last;
		if(n & 1)last = n-1;
		else last = n;
 
		bool flag = false;
 
		cout<<last - 3<<" ";
 
		int i = last + 1;
 
		if(n % 2 == 1){
			if(i <= n)cout<<i<<" ";
		}
		i -= 2;
 
		while(i > 0){
			if(i != last-3)cout<<i<<" ";
			i -= 2;
		}
		cout<<"\n";
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
 
