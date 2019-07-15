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

    int n,k;
    cin>>n>>k;
    int h[n+1];
    for(int i = 1; i <= n; i++)cin>>h[i];

    int dp[n+1];
    dp[n] = 0;
    dp[n-1] = abs(h[n-1]-h[n]);

    for(int i = n-2; i >=1; i--){
        dp[i] = INT_MAX;
        for(int j = i+1; j <=n && j-i<=k; j++){
            dp[i] = min(dp[i],dp[j]+abs(h[i]-h[j]));
        }
    }
    cout<<dp[1];

}
