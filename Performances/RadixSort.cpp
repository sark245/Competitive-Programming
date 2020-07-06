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
    

void countSort(int a[], int n, int exp){
    int out[n];
    int i, count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(a[i]/exp) % 10]++;
    
    for(int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    for(int i = n-1; i >= 0; --i){
        out[count[(a[i]/exp) % 10] - 1] = a[i];
        count[(a[i]/exp)%10]--;
    }

    for(int i = 0; i < n; i++){
        a[i] = out[i];
    }

}

void radixSort(int a[], int n){
    int mx = -1;
    for(int i = 0; i < n; i++){
        mx = max(mx, a[i]);
    }

    for(int exp = 1; mx/ exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int main(){
   IOS

   int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
   int n =  sizeof(a)/sizeof(a[0]);

   radixSort(a, n);
   for(int i = 0; i < n; i++)cout<<a[i]<<" ";




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

