//
// Created by sark2 on 06-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
/*
bool  isSubsetSum(int S[],int n, int sum){
    if(sum == 0)return true;

    if(n == 0 && sum != 0) return false;
    if(S[n-1] > sum)return isSubsetSum(S,n-1,sum);

    return isSubsetSum(S,n-1,sum-S[n-1]) || isSubsetSum(S,n-1,sum);
}
*/
bool isSubsetSum(int s[], int n, int sum){

    bool dp[n+1][sum+1];
    memset(dp,false,sizeof dp);

    for(int i = 0; i <= n; i++)
        dp[i][0] = true;

    for(int i = 1; i <= sum; i++){
        dp[0][i] = false;
    }

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < s[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - s[i - 1]];
            }
        }
    }
     return dp[n][sum];
}


int main() {
    IOS

    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);
    cout<<isSubsetSum(set,n,sum);

}
