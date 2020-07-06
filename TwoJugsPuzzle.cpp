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



void twoJug(int a, int b, int t){
    map<pii, int> mp;
    bool isPoss = true;

    vector<pii> path;

    queue<pii> q;
    q.push({0, 0});

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        if(mp[{u.first, u.second}] == 1)continue;

        if(u.first > a || u.second > b || u.first < 0 || u.second < 0)continue;

        path.pb({u.first, u.second});

        mp[{u.first, u.second}] = 1;

        if(u.first == t || u.second == t){
            isPoss = true;
            if(u.first == t){
                if(u.second != 0)
                    path.pb({u.first, 0});
            }
            else{
                if(u.first != 0)
                    path.pb({0, u.second});
            }

            for(int i = 0; i < sz(path); i++){
                cout<<"("<<path[i].first<<", "<<path[i].second<<")\n";
            }
            break;
        }

        q.push({u.first, b});
        q.push({a, u.second});

        for(int ap = 0; ap <= max(a, b); ap++){
            int c = u.first + ap;
            int d = u.second - ap;

            if(c == a || (d == 0 && d >= 0))
                q.push({c, d});
            
            c = u.first - ap;
            d = u.second + ap;

            if((c == 0 && c >= 0) || d == b)
                q.push({c, d});
        }

        q.push({a, 0});
        q.push({0, b});
    }

    if(!isPoss)cout<<"No Solution\n";
}



int main(){
   IOS

    int a = 4, b = 3, target = 2;

    twoJug(a, b, target);

    

}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1) res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

