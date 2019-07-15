//
// Created by sark2 on 11-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
int solve(int n,int a[]){

    unordered_map<int,int>dp[n+1];

    int res= 0;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >=0; j--){
            int dif = a[i] - a[j];
            if(dp[j].count(dif) != 0){
                res += dp[j][dif];
                dp[i][dif] += (dp[j][dif]+1);
            }
            else
                dp[i][dif]++;
        }
    }


    return res;
}


int main() {
    IOS

    int n;
    cin>>n;
    int a[n+1];
    for(int i = 0; i < n; i++)cin>>a[i];
    cout<<solve(n,a);


}
