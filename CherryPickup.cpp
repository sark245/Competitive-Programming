//
// Created by sark2 on 14-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
int m,n;
int ***dp;
int **grid;
int cherrypick(int r1, int c1, int r2);
int main() {
    IOS

    cin>>m>>n;
   grid = new int*[m];
    for(int i = 0; i < m; i++){
        grid[i] = new int[n];
        for(int j = 0; j < n; j++)
            cin>>grid[i][j];
    }

    dp = new int** [n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = new int*[n+1];
            for(int j = 0; j <= n; j++)
                dp[i][j] = new int[n+1];
        }


    fill_n(&dp[0][0][0],(n+1)*(n+1)*(n+1) ,INT_MIN);
    cout<<endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j<=n; j++){
            for(int k = 0; k <= n; k++){
                cout<<dp[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }

    cout<<cherrypick(0,0,0);

    cout<<endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j<=n; j++){
            for(int k = 0; k <= n; k++){
                cout<<dp[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }


}

int cherrypick(int r1, int c1, int r2){
        int c2 = r1 + c1 -r2;
    if(r1 == n||r2==n||c1==n||grid[r1][c1]==-1||grid[r2][c2]==-1){
        return -1;
    }
    else if(r1 == n-1 && c1 == n-1){
        return grid[r1][c1];
    }
    else if(dp[r1][c1][r2] != INT_MIN){
        return dp[r1][c1][r2];
    }
    else{
        int ans = grid[r1][c1];
        if(c1!=c2) ans+=grid[r2][c2];
        ans += max(max(cherrypick(r1+1,c1,r2+1),cherrypick(r1+1,c1,r2)),max(cherrypick(r1,c1+1,r2+1),cherrypick(r1,c1+1,r2)));
        dp[r1][c1][r2] = ans;
        return ans;
    }
}
