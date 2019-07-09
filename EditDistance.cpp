//
// Created by sark2 on 09-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

int ed(int n, int m, string s1, string s2){

    int dp[n+1][m+1];

    for(int i = 0; i<=m; i++){
        dp[n][i] = m-i;
    }

    for(int i = 0; i <= n; i++){
        dp[i][m] = n-i;
    }

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            dp[i][j] = (s1[i]==s2[j] ? dp[i+1][j+1] : 1 + min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1])));
        }
    }
    return dp[0][0];
}


int main() {
    IOS
    cases{
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        cout<<ed(n,m,s1,s2)<<endl;
    };


}
