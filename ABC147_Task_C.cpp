//
// Created by sark2 on 19-12-2019.
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

    int n; cin>>n;

    vector<int>a(n);
    int x[n+5][n+5], y[n+5][n+5];


    for(int i = 0; i < n; i++){
        cin>>a[i];
        for (int j = 1; j <= a[i]; j++) {
            cin>>x[i+1][j]>>y[i+1][j];
        }
    }

    int ans = 0;
    //Bitmask Brute Forcing
    //We iterate over all the subsets of a set using this method
    for(int mask = 1; mask < (1<<n); mask++){
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(!(mask & (1<<i))){   //If this guy is telling the truth then skip him
                continue;
            }
            for(int j = 1; j <= a[i]; j++){ //the guy is telling a lie
                if(((mask >> (x[i+1][j]-1)) & 1)^y[i+1][j])ok = false;  //If any inconsistency is observed then we set ok to false !!
            }
        }
        if(ok) ans = max(ans, __builtin_popcount(mask));
    }

    cout<<ans<<"\n";




}
