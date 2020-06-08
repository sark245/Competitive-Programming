//https://codeforces.com/contest/1365/problem/D

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
    
int n, m;
char a[55][55];
bool vis[55][55];

bool isValid(int x, int y){
    return x < n and y < m and x >= 0 and y >= 0;
}

int dx[4] = {1, -1, 0,  0};
int dy[4] = {0,  0, 1, -1};

void dfs(int x, int y){
    vis[x][y] = true;

    for(int i = 0; i < 4; i++){
        if(isValid(x + dx[i], y + dy[i]) and !vis[x + dx[i]][y + dy[i]]){
            if(a[x + dx[i]][y + dy[i]] == '.'){
                dfs(x + dx[i], y + dy[i]);
            }else if(a[x + dx[i]][y + dy[i]] == 'G'){
                a[x + dx[i]][y + dy[i]] = 'Y';
                dfs(x + dx[i], y + dy[i]);
            }
        }
    }
}

int main(){
   IOS

    int t; cin>>t;
    while(t--){
         cin>>n>>m;
        queue<pii> q;
        int cnt = 0;

        memset(vis, false, sizeof vis);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>a[i][j];
                if(a[i][j] == 'B'){
                    q.push({i, j});
                }   
                if(a[i][j] == 'G')cnt++;                 
            }
        }

        bool flag  = true;

        while(!q.empty()){
            pii rem = q.front(); q.pop();
            int x = rem.first;
            int y = rem.second;

            for(int i = 0; i < 4; i++){
                if(isValid(x + dx[i], y + dy[i])){
                    if(a[x + dx[i]][y + dy[i]] == '.')
                        a[x + dx[i]][y + dy[i]] = '#';
                    else if(a[x + dx[i]][y + dy[i]] == 'G'){
                        flag = false;
                        break;
                    }
                }
            }

            if(!flag)break;
        }

        if(a[n-1][m-1] == '#' and cnt > 0){
            cout<<"No\n";
            continue;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == '#')vis[i][j] = true;
            }
        }

        dfs(n-1, m - 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'G'){
                    flag = false;
                    break;
                }
            }
        }

        cout<<(flag ? "Yes\n" : "No\n");

    }
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

