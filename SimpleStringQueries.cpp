//https://atcoder.jp/contests/abc157/tasks/abc157_e

//Created by Kira

#include <bits/stdc++.h>
using namespace std;

#define IOS                 \
    cin.sync_with_stdio(0); \
    cin.tie(0);             \
    cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);

const int N = 5e5+10;

int n;


struct S{

    vector<bool> cnt;
    
    S() {
        cnt.assign(26, false);
    }
    S(vector<bool> cnt) : cnt(cnt){}
};


 S combine(S a, S b){
        S res;

        for(int i = 0; i < 26; i++){
            res.cnt[i] = a.cnt[i] | b.cnt[i];
        }

        return res;
}

S t[2 * N];

void build()
{
    for (int i = n - 1; i >= 0; --i)
        t[i] = combine(t[i<<1], t[i<<1 | 1]);
}

void modify(int p, S val)
{ //Set Value at position p
    for (t[p += n] = val; p > 1; p >>= 1)
        t[p >> 1] = combine(t[p],t[p ^ 1]);
}

S query(int l, int r)
{ //query on interval [l,r)

    S resL, resR;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            resL  = combine(resL, t[l++]);
        if (r & 1)
            resR  = combine(resR, t[--r]);
    }
    return combine(resL, resR);
}

int main(){
    IOS
    
    cin>>n;

    string s; cin>>s;
    int q; cin>>q;


    for(int i = n; i < 2*n; i++){
        t[i].cnt[s[i-n]-'a'] = true;
    }

    build();

    for(int i = 0; i < q; ++i){
        int type; cin>>type;

        if(type == 1){
            int pos; char val;
            cin>>pos>>val; --pos;
            S nn; nn.cnt[val-'a'] = true;
            modify(pos, nn);

        }else if (type == 2){
            int L, R; cin>>L>>R; L--;
            S res = query(L, R);         
            int fres = 0; 
            for(int i = 0; i < 26; ++i){
                if(res.cnt[i])fres++;
            }

            cout<<fres<<"\n";
        }
    }

}

ll pwr(ll a, ll b)
{
    a %= mod; //Remove mod if not required
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}
