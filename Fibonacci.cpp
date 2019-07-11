//
// Created by sark2 on 05-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
int fibonacci(int n){
    int fb[n+1];
    memset(fb,0,sizeof fb);
    fb[0] = 0;
    fb[1] = 1;
    for(int i = 2; i <= n; i++){
     fb[i] = fb[i-1] + fb[i-2];
    }

    return fb[n];
}


int main() {
    IOS
    int n;
    cin>>n;
    cout<<fibonacci(n);


}
