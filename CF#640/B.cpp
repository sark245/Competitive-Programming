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
 
		if(n % k == 0){
			cout<<"YES\n";
			for(int i = 1; i <= k; i++){
				cout<<n/k<<" ";
			}
			cout<<endl;
		}else{
 
		if(k > n){
			cout<<"NO\n";
			continue;
		}
 
		if(n% 2 == 0){
			if(k % 2 == 0){
				cout<<"YES\n";
				for(int i = 1; i < k; i++){
					cout<<1<<" ";
				}
 
				cout<<n - (k-1)<<"\n";
			}
			else{
				if(k * 2 > n){
					cout<<"NO\n";
					continue;
				}else{
					cout<<"YES\n";
					for(int i = 1; i < k; i++){
						cout<<2<<" ";
					}
 
					cout<<n - 2 *(k-1)<<"\n";
				}
			}
		}else{
			if(k % 2 == 0){
				cout<<"NO\n";
				continue;
			}else{
				cout<<"YES\n";
				for(int i = 1; i < k; i++){
					cout<<1<<" ";
				}
 
				cout<<n - (k-1)<<"\n";
			}
		}
		}
 
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
 
