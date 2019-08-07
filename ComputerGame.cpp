//
// Created by sark2 on 24-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
typedef long long ll;
int main() {
    IOS
    int q;
    cin>>q;
    while(q--){
        ll k,n,a,b;
        cin>>k>>n>>a>>b;
        ll f = (k-b*n)/(a-b);
        if(f > n){
            cout<<n;
        }
        else {
            if(k-b*n == 0){
                cout<<-1;
            }
            else if(f == 0){
                cout<<0;
            }
            else if((k-b*n) % (a-b) != 0){
                cout<<f;
            }
            else{
                cout<<f-1;
            }
        }

        cout<<endl;
    }


}
