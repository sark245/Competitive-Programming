//https://atcoder.jp/contests/abc153/tasks/abc153_f

//Created by Kira

//A good greedy problem. Uses Binary search and can also be done using Segment Trees and Binary Indexed Trees.

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
    
int f(int h, int a){
    if(h % a == 0)
        return (h/a);
    else
        return h/a+1;
}



int main(){
   IOS

   int N, D, A; cin>>N>>D>>A;

   vector<pii> x(N);

   for(int i= 0; i < N; i++){
       cin>>x[i].first>>x[i].second;
   }

   sort(all(x));

   ll res = 0;

   vi X(N), H(N);
   for(int i = 0; i < N; i++) X[i] = x[i].first, H[i] = x[i].second;

   vector<ll> CS(N+1,0);

    //CS is the cummulative sum that we use for storing the 
    //prefix sum till ith index.
    //We add A-1 in cnt so that we get atleast 1 if the difference is less than A
    //'d' is basically the total amt of health reduced or any
    //monster in that range!!

   for(int i = 0; i < N; i++){
       if(x[i].second > CS[i]){
           int idx = upper_bound(all(X), X[i] + 2*D)-X.begin();
           ll cnt = (H[i]-CS[i] + A-1)/A, d = A*cnt;
           res += cnt;
           CS[i] += d;
           CS[idx] -= d;
        }
        CS[i+1] += CS[i];
   }

    cout<<res<<"\n";


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

