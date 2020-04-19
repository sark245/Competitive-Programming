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
    
struct Box{
    int h, w, d;
    Box(){}
    Box(int h, int w, int d): h(h), w(w), d(d){}
};

struct comp
{
    bool operator()(const Box &a, const Box &b){
        return a.d * a.w > b.w*b.d;
    }
};

int maxHeight(int height[],int width[],int length[],int n)
{
    Box rot[3*n];
    int idx = 0;
    for(int i = 0; i < n; i++){
        rot[idx] = Box(height[i], max(width[i], length[i]), min(width[i], length[i]));
        idx++;
        rot[idx] = Box(width[i], max(height[i], length[i]), min(height[i], length[i]));
        idx++;
        rot[idx] = Box(length[i], max(width[i], height[i]), min(width[i], height[i]));
        idx++;
    }
    n *= 3;

    sort(rot, rot + n, comp());

   

    vi dp(n+1);

    for(int i = 0; i < n; i++){
        dp[i] = rot[i].h;
    }

    for(int i =1; i < n; i++){
        for(int j = i-1; j >= 0; --j){
            if(rot[i].d < rot[j].d and rot[i].w < rot[j].w)
                dp[i] = max(dp[i], dp[j] + rot[i].h);                
        }
    }
   

    int mx = 0;
    for(int i = 0; i < n; i++)mx = max(mx, dp[i]);

    return mx;
}




int main(){
   IOS

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        int A[1000], B[1000], C[10001];

        for(int i = 0; i < n; i++){
            cin>>A[i]>>B[i]>>C[i];
        }
        cout<<maxHeight(A, B, C, n)<<"\n";
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

