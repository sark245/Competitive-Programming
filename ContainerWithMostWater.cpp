//
// Created by sark2 on 29-06-2019.
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
    int a[n+2];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int i = 0, j = n-1;
    int res = 0;

    while(j!=i){

        res = max(res,min(a[i],a[j])*(j-i));
        (a[j] > a[i]) ? i++ : j--;

    }
    cout<<res;

}
