//
// Created by sark2 on 02-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

int main() {
    IOS
    int n;
    cin>>n;
    int a[n+1];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        if(abs(a[i]-i) > 1){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";

}
