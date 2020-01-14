//
// Created by sark2 on 14-01-2020.
//
 
#include "bits/stdc++.h"
 
using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)
 
using ll = long long;
using ld = long double;
 
const int mod = 1e9 + 7;
 
int main() {
    IOS
 
    int n; cin>>n;
 
    vector<int> a(n);
    for(int& x : a)cin>>x;
 
    int cur = 1;
 
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == cur){
            cur++;
        }else{
            ans++;
        }
    }
 
    cout<<(ans == n ? -1 : ans)<<"\n";
 
 
}
