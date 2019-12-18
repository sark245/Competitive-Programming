//
// Created by sark2 on 11-07-2019.
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

    int dp[n+1];
    dp[n] = 0;
    if (n >= 1)
        dp[n - 1] = 1;

    for (int i = n - 2; i >= 1; i--) {
        dp[i] = dp[i + 1] + 1;
        if (2 * i <= n)
            dp[i] = min(dp[i], dp[2 * i] + 1);
        if (3 * i <= n)
            dp[i] = min(dp[i], dp[3 * i] + 1);
    }
    cout<<dp[1];

}
