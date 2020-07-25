
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

   int n; cin>>n;
    priority_queue<int> l;
    priority_queue<int, vi, greater<int>>r;

    int med = 0, size;

   for(int i = 0; i < n; i++){
       int x; cin>>x;

       if(x > med){
           r.push(x);
       }else{
           l.push(x);
       }
       if(sz(l) - sz(r) >= 2){
           r.push(l.top());
           l.pop();
       }else if(sz(r) - sz(l) >= 2){
           l.push(r.top());
           r.pop();
       }

       size = sz(l) + sz(r);
       if(size & 1){
            if(sz(l) > sz(r))med = l.top();
            else med = r.top();
       }else{
           med = (l.top() + r.top())/2;
       }

    cout<<med<<"\n";
       
       


   }

    







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

