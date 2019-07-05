//
// Created by sark2 on 05-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
int minSteps(int n, int a[]){

    if(n == 0 || a[0] == 0){
        return -1;
    }
    int dp[n+5];
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        dp[i] = INT_MAX;
        for(int j = 0; j < i; j++){
            if(j + a[j] >= i && dp[j] != INT_MAX){
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    if(dp[n-1] == INT_MAX) return -1;
    return dp[n-1];



}
int main() {
    IOS

    cases{
     int n;
     cin>>n;
     int a[n+1];
     for(int i = 0; i < n; i++)cin>>a[i];

     cout<<minSteps(n,a)<<endl;
    }


}
