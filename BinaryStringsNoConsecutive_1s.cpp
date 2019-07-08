//
// Created by sark2 on 07-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
typedef long long ll;
#define mod 1000000007
int solve(int n){

    ll dp[2][n+1];
    dp[0][0] = 1;
    dp[1][0] = 1;

    for(int i = 1; i < n; i++){
        dp[0][i] = (dp[0][i-1]%mod + dp[1][i-1]%mod)%mod;
        dp[1][i] = dp[0][i-1]%mod;
    }

    return (dp[0][n-1]%mod + dp[1][n-1]%mod)%mod;


}


int main() {
    IOS

    cases{
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }

}
