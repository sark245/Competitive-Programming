//
// Created by sark2 on 20-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
typedef long long ll;

int main() {
    IOS
    int n;
    cin>>n;
    ll h1[n+1],h2[n+1];
    for(int i = 0; i < n; i++){
        cin>>h1[i];
    }
    for(int i = 0; i < n ; i++){
        cin>>h2[i];
    }

    ll u[n+1], d[n+1];

    u[n-1] = h1[n-1];
    d[n-1] = h2[n-1];

    for(int i = n-2; i >=0; i--){
        u[i] = max(h1[i] + d[i+1], u[i+1]);
        d[i] = max(h2[i] + u[i+1], d[i+1]);
    }
    cout<<max(u[0],d[0]);


}
