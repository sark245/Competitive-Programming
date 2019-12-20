//
// Created by sark2 on 19-12-2019.
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

    ll n; cin>>n;
    ll a[n+5];

    for(ll i = 0; i < n; i++)cin>>a[i];

    ll sum = 0;
    for(int i = 0; i < 60; i++){

        ll zc = 0;
        ll unit_sum =  0;
        for(ll j = 0; j < n; j++){
            if(a[j] % 2 == 0)
                zc++;
            a[j] /= 2;
        }
        unit_sum = (((((1LL << i)%mod)*(n-zc))%mod * zc) % mod)%mod;

        sum += unit_sum, sum %= mod;
    }

    cout<<sum%mod<<"\n";



}
