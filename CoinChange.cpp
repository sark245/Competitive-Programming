//
// Created by sark2 on 06-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

int main() {
    IOS

    cases{
     int m;
     cin>>m;
     int a[m+1];
     for(int i = 0; i < m; i++){
         cin>>a[i];
     }
     int N;
     cin>>N;

     int dp[N+1][m];
     memset(dp,0,sizeof dp);

     for(int i = 0; i < m; i++){
         dp[0][i] = 1;
     }

     for(int i = 1; i < N+1; i++){
         for(int j = 0; j < m; j++){

             int x =  (i-a[j] >= 0)?dp[i-a[j]][j] : 0;
             int y = (j>=1)?dp[i][j-1] : 0;
             dp[i][j] = x+y;

         }
     }

     for(int i = 0; i <= N; i++){
         for(int j = 0; j < m; j++){
             cout<<dp[i][j]<<" ";
         }
         cout<<endl;
     }

     cout<<dp[N][m-1];

    }

}
