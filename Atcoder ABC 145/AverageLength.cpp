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
    



int main(){
   IOS

    int n; cin>>n;
    vi x(n), y(n);

    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i];
    }

    vector<int> a(n);
    iota(all(a), 0);

    double ans = 0;
    int cnt = 0;
    int x1, x2, y1, y2;
    do{
        double sum = 0;
        for(int i = 0; i < n - 1; i++){
            x1 = x[a[i]], x2 = x[a[i + 1]];
            y1 = y[a[i]], y2 = y[a[i + 1]];
            sum += (double)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
        ans += sum;
        cnt++;
    }while(next_permutation(all(a)));

    cout<<fixed<<setprecision(7);
    cout<<ans/(double)cnt<<"\n";
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

