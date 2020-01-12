//https://www.codechef.com/problems/SNSOCIAL


//
// Created by sark2 on 30-12-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int N = 600;

using pii = pair<int,int> ;
using pli = pair<ll, int> ;
const int inf = 1e8;

vector<vector<int>> a(N, vector<int> (N, inf));
int n, m;

bool isdelim(pair<int, int> &p);

int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = { 0,  0, 1, -1 ,-1, -1, 1 , 1};

bool isValid(int i, int j){
    return i >= 1 && i <= n && j >= 1 && j <= m;
}


bool isSource(int i, int j){
    int mx = INT_MIN;
    for(int x = 0; x < 8; x++){
        if(isValid(i+dx[x], j + dy[x]))
            mx = max(mx, a[i+dx[x]][j+dy[x]]);
    }

    return a[i][j] >= mx;
}



int main() {
    IOS

    CASES{
       cin>> n>>m;
       a.resize(N, vector<int>(N, inf));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin>>a[i][j];
            }
        }

        queue<pii> q;
        int ans = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(isSource(i,j))
                    q.push({i,j});
            }
        }

        q.push({-1,-1});    //Delimiter

        while(!q.empty()){

            bool flag = false;

            while(!isdelim(q.front())) {
                int i = q.front().first, j = q.front().second;
                if (a[i][j] > a[i - 1][j]) {
                    a[i - 1][j] = a[i][j];
                    if(!flag)ans++, flag = true;
                    if(isValid(i-1, j) && isSource(i-1,j))
                        q.push({i-1, j});
                }
                if (a[i][j] > a[i][j-1]) {
                    a[i][j-1] = a[i][j];
                    if(!flag)ans++, flag = true;
                    if(isValid(i, j-1) && isSource(i,j-1))
                        q.push({i, j-1});
                }
                if (a[i][j] > a[i][j+1]) {
                    a[i][j+1] = a[i][j];
                    if(!flag)ans++, flag = true;
                    if(isValid(i, j+1) && isSource(i,j+1))
                        q.push({i, j+1});
                }

                if (a[i][j] > a[i + 1][j]) {
                    a[i+1][j] = a[i][j];
                    if(!flag)ans++, flag = true;
                    if(isValid(i+1, j) && isSource(i+1, j))
                        q.push({i+1, j});
                }
                if (a[i][j] > a[i - 1][j-1]) {
                    a[i - 1][j-1] = a[i][j];
                    if(!flag)ans++, flag = true;
                    if(isValid(i-1 , j-1) && isSource(i-1, j-1))
                         q.push({i-1, j-1});
                }
                if (a[i][j] > a[i - 1][j+1]) {
                    a[i - 1][j+1] = a[i][j];
                    if(!flag)ans++, flag = true;
                    if(isValid(i-1, j+1) && isSource(i-1, j+1))
                        q.push({i-1, j+1});
                }

                if (a[i][j] > a[i + 1][j-1]) {
                    a[i + 1][j-1] = a[i][j];
                    if(!flag)ans++, flag = true;
                    if(isValid(i+1, j-1) && isSource(i+1, j-1))
                        q.push({i+1, j-1});
                }
                if (a[i][j] > a[i+1][j+1]) {
                    a[i + 1][j+1] = a[i][j];
                    if(!flag)ans++, flag = true;
                    if(isValid(i+1, j+1) && isSource(i+1, j+1))
                        q.push({i+1, j+1});
                }

                q.pop();
            }
            q.pop();


            if(!q.empty()){
                q.push({-1,-1});
            }
        }

        cout<<ans<<"\n";
    }
}

bool isdelim(pair<int, int> &p) {
    return p.first==-1 && p.second == -1;
}


