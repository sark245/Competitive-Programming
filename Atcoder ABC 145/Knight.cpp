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
    

const int N = 1e6 + 5;

int mul(int a, int b){
    return ((ll)a * b)  % mod;
}

int f[N];

int inverse(int x){
    return pwr(x, mod - 2) % mod;
}

int nCk(int n, int k){
    if(k > n)return 0;
    return mul(f[n] % mod, mul(inverse(f[n-k]), inverse(f[k])) % mod);
}

int main(){
   IOS

    int x, y;
   cin>>x>>y;

    f[0] = f[1] = 1;
    for(int i = 2; i < N - 2; i++){
        f[i] = mul(f[i - 1], i);
    }

   if((x + y) % 3 != 0){
       cout<<0<<"\n";
       return 0;
   }

   int num = (x + y)/3 + 1;

   int s = 2 * ((x + y)/3);

   if(x > s){
       cout<<"0\n";
       return 0;
   }

   int d = s - x;
   cout<<nCk(num-1, d)<<"\n";

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

