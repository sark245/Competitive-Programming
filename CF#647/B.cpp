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
        vi mp(1024);
        for(int &x : a)cin>>x, mp[x]++;

        if(n & 1){
            cout<<"-1\n";
        }else{
            bool found = false;
            for(int k = 1; k <= 1023; k++){
                bool flag = true;
                for(int i = 0; i < n; i++){
                    if(mp[a[i]] != mp[a[i] ^ k])
                        flag = false;
                }
                if(flag){
                    cout<<k<<"\n";
                    found = true;
                    break;
                }
            }

            if(!found)cout<<-1<<"\n";
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

