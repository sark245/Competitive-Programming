#include<bits/stdc++.h>
using namespace std;
int solve(int m, int n,const vector<vector<int>>& mine){

    int dp[m+1][n+1];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = mine[i][j];
        }
    }


    for(int j = n-2; j>=0; j--){
        for(int i = m-1; i >=0; i--){

            dp[i][j] += max(dp[i][j+1],max(((i != 0)?dp[i-1][j+1]:0),((i != m-1)?dp[i+1][j+1]:0)));
        }
    }
  /*  for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    int gmax = 0;
    for(int i = 0; i < m; i++){
        gmax = max(dp[i][0],gmax);
    }
    return gmax;



}

int main() {

    int T;
    cin>>T;
    while(T--){
        int m,n;
        cin>>m>>n;
        vector<vector<int>>mine(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)cin>>mine[i][j];
        }
        cout<<solve(m,n,mine)<<endl;

    }

    return 0;
}