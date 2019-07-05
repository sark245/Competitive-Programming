//
// Created by sark2 on 03-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

int main() {
    IOS

    int n,k;
    cin>>n>>k;
    int a[n+2];
    for(int i = 0;i < n; i++){
        cin>>a[i];
    }

    int end = a[0] + k;
    int ptime = 0;
    int start = a[0];
    for(int i = 1; i < n; i++){
        if(end > a[i]){
            end = a[i]+k;

        }
        else{
            ptime += end - start;
            start = a[i];
            end = a[i] + k;
        }
    }
    ptime += end-start;

    cout<<ptime;

}
