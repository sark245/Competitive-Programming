//
// Created by sark2 on 08-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
int eggBreak(int n ,int k){

    int dp[n+1][k+1];
    memset(dp,0,sizeof dp); //Takes care of the base case where we have 0 eggs

    for(int i = 0; i <= k; i++){
        dp[1][i] = i;
    }
    for(int i = 1; i <= n; i++){
        dp[i][1] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= k; j++){
            dp[i][j] = INT_MAX;
            for(int x = 1; x <= j; x++) {
                int res = 1 + max(dp[i-1][x - 1], dp[i][j-x]);

                dp[i][j] = min(dp[i][j],res);
            }
        }
    }
    return dp[n][k];
}
int main() {
    IOS

    cases{
     int n,k;
     cin>>n>>k;
     cout<<eggBreak(n,k)<<endl;

    }

}
