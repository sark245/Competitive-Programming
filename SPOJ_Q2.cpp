//https://www.spoj.com/problems/MIXTURES/
//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);

const ll INF = 2e18; 
const int N = 105;


int main(){
   IOS
    int n; 
    ll dp1[N][N], dp2[N][N];

while(scanf("%d", &n) != EOF){
    
       
        vi ar(n);
        for(int i = 0; i < n; i++)scanf("%d", &ar[i]);

        memset(dp1, 0ll, sizeof dp1);
        memset(dp2, 0ll, sizeof dp2);   

        for(int i = 0; i < n; i++)dp1[i][i] = ar[i];  

        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n-l+1; i++){
                int j = i + l -1;
                dp2[i][j] = INF;
                for(int k = i; k < j; k++){
                    if(dp2[i][j] > dp2[i][k] + dp2[k+1][j] + dp1[i][k] * dp1[k+1][j]){
                        dp2[i][j] = min(dp2[i][j],  dp2[i][k] + dp2[k+1][j] + dp1[i][k] * dp1[k+1][j]);
                        dp1[i][j] = (dp1[i][k] + dp1[k+1][j])%100;
                    }
                }
            }
        }

   

        cout<<dp2[0][n-1]<<"\n";
    }

}



