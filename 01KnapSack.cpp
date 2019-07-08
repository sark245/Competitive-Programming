//
// Created by sark2 on 07-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
int Knapsack(int n, int W, int wt[], int p[]){

    int dp[n+1][W+1];

    for(int i = 0; i <= W; i++)dp[0][i] = 0;

    for(int i = 0; i <= n; i++)dp[i][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int  j = 1; j <= W; j++){

            dp[i][j] = dp[i-1][j];
            if(j >= wt[i]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-wt[i]] + p[i]);
            }
         /*   cout<<dp[i][j]<<" ";*/
        }
        /*cout<<endl;*/
    }

    return dp[n][W];
}

int main() {
    IOS

    cases{
     int n;
     cin>>n;
     int W;
     cin>>W;
     int wt[n+1], p[n+1];
        for(int i = 1; i <= n; i++)cin>>p[i];
        for(int i = 1; i <= n; i++)cin>>wt[i];
     cout<<Knapsack(n,W,wt,p)<<endl;
    }


}
