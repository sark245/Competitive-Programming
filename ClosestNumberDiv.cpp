//
// Created by sark2 on 01-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

int main() {
    IOS
    cases{
     int m,n;
     cin>>m>>n;

     int p = ceil((double)m / n) * n;
     int q = floor((double)m / n) *n;
     if(abs(p-m) < abs(q-m)){
         cout<<p<<endl;
     }
     else if(abs(p-m) > abs(q-m)){
         cout<<q<<endl;
     }
     else{
         if(p < 0){
             cout<<-1*max(abs(p),abs(q))<<endl;
         }
         else{
             cout<<max(p,q)<<endl;
         }
     }
    }

}
