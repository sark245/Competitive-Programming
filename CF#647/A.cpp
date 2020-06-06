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
        ll a, b; cin>>a>>b;

        ll ans = 0;

        if(a == b){
            cout<<"0\n";
        }
        else if(a > b){
            //divide
            if(a % b == 0){
                ll c = a/b;
                if(__builtin_popcount(c) > 1){
                    cout<<-1<<"\n";
                }else{
                    int p;
                    for(int i = 0; i < 60; i++){
                        if(c & (1ll<<i)){
                            p = i;
                            break;
                        }
                    }

                    ans += p/3;
                    p %= 3;
                    ans += p/2;
                    p %= 2;
                    ans += p;

                    cout<<ans<<"\n";
                }
            }else{
                cout<<-1<<"\n";
            }
        }else{
            //multiply

            if(b % a == 0){
                ll c = b/a;
                if(__builtin_popcount(c) > 1){
                    cout<<-1<<"\n";
                }else{
                    int p;
                    for(int i = 0; i < 60; i++){
                        if(c & (1ll<<i)){
                            p = i;
                            break;
                        }
                    }

                    ans += p/3;
                    p %= 3;
                    ans += p/2;
                    p %= 2;
                    ans += p;

                    cout<<ans<<"\n";
                }
                
            }else{
                cout<<"-1\n";
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
 
