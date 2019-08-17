//
// Created by sark2 on 17-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
ld solve(ld p[], int n){

    ld dp[n+1][n+1];
    memset(dp,0.0,sizeof dp);
    dp[0][0] = 1.0;
    for(int i = 1; i <=n; i++) {
        for (int j = 0; j <= i; j++) {

            if (j == 0) {
                dp[i][j] = dp[i - 1][j] * (1 - p[i]);
            } else {
                dp[i][j] = (1 - p[i]) * dp[i - 1][j] + p[i] * dp[i - 1][j - 1];
            }

        }
    }

    ld ans = 0.0;
        for(int i = (n+1)/2 ; i <= n; i++){
            ans += dp[n][i];
        }

    return ans;
    }



int main() {
    IOS

    int n;
    cin>>n;
    ld p[n+5];
    for(int i = 1; i <= n; i++) cin>>p[i];

    cout<<fixed<<setprecision(10)<<solve(p,n);

}
