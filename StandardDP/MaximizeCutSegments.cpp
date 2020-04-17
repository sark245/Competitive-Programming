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

        int x[3]; 
        for(int i = 0; i < 3; i++)cin>>x[i];

        //a*x + b*y + c*z = n 
        //max(a+b+c) a,b,c >= 0
        //price for each cut is 1
        // f(n) = max(1 + f(n-r)) f(x) = 1

        int f[n+5];
        memset(f, 0, sizeof f);
        for(int i = 0; i < 3; i++)if(x[i] <= n)f[x[i]] = 1;

        for(int i = 1; i <= n; i++){
            if(f[i] > 0){
                for(int j = 0; j < 3; j++){
                    if(i + x[j] <= n)
                        f[i + x[j]] = max(f[i+x[j]], 1+f[i]);
                }
            }
        }

        cout<<f[n]<<"\n";
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

