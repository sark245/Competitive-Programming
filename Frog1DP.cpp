//
// Created by sark2 on 14-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

int main() {
    IOS
    int n;
    cin>>n;
    int h[n+1];
    for(int i = 1 ; i <= n; i++)cin>>h[i];

    int dp[n+1];
    dp[n] = 0;
    dp[n-1] = abs(h[n-1]-h[n]);
    for(int i = n-2; i >=0; i--) {
        dp[i] = min(dp[i+1] + abs(h[i] - h[i+1]), dp[i+2] + abs(h[i] - h[i+2]));
    }
    cout<<dp[1];


}
