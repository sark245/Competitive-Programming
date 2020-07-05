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
    

void countSort(vi &A){
    int max = *max_element(all(A));
    int min = *min_element(all(A));

    int range = max - min + 1;
    vi cnt(range), op(sz(A));

    for(int x : A){
        cnt[x - min]++;
    }

    for(int i = 1; i < range; i++){
        cnt[i] += cnt[i-1];
    }

    for(int i = sz(A) - 1; i >= 0; --i){
        op[cnt[A[i] - min] - 1] = A[i];
        cnt[A[i] - min]--;
    }
    A = op;
}



int main(){
   IOS

   vi A(10);

   for(int i = 0; i < 10; i++){
       cin>>A[i];
   }

   countSort(A);

   for(int i = 0; i < 10; i++){
       cout<<A[i]<<" ";
   }




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

