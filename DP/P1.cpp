//Created by Kira
//https://codeforces.com/contest/626/problem/F

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
    
void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int mul(int a, int b){
    return ((ll)a * b) % mod;
}

int n, k, a[210], ans, dp[210][210][1010];

int main(){
   IOS

   cin>>n>>k;
   for(int i = 1; i <= n; i++)cin>>a[i];

    sort(a + 1, a + n + 1);
    memset(dp, 0, sizeof dp);

   dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){    //ith element of array
        for(int j = 0; j <= i; j++){    //Number of open groups
            for(int total = 0; total <= k; total++){
                int v = dp[i-1][j][total], nxt = total + j * (a[i] - a[i-1]);
                if(nxt <= k){
                //Case 1: Self Closed Set               
                    add(dp[i][j][nxt], v);
                
                    //Case 2: Self Open Set
                    add(dp[i][j+1][nxt] , v);
                    if(j > 0){
                        //Case 3: Close an Open set
                        add(dp[i][j-1][nxt], mul(j, v) % mod);
                        //Case 4: Add to Open and don't close
                        add(dp[i][j][nxt], mul(j, v) % mod);
                    }
                }
            }
        }  
    } 

    ans = 0;
    for(int total = 0; total <= k; total++){
        add(ans, dp[n][0][total]);
    }

    cout<<ans <<"\n";

   
}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1)
        res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

