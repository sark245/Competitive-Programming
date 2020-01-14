//
// Created by sark2 on 14-01-2020.
//
 
#include "bits/stdc++.h"
 
using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)
 
using ll = long long;
using ld = long double;
 
const int mod = 1e9 + 7;
 
int main() {
    IOS
 
    ll n; cin>>n;
    if(n&1){
        cout<<0<<"\n";
    }else{
        ll f = 5;
        ll ans = 0;
        n /= 2;
        while(n/f){
            ans += n/f;
            f *= 5;
        }
        cout<<ans<<"\n";
    }
 
}
