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
    string s;
    cin>>s;

    int a, b; cin>>a>>b;

    int n = s.length();

    int rema[n+5], remb[n+5];
    rema[0] = (s[0]-'0')%a;

    for(int i = 1; i < n; i++){
        rema[i] = (rema[i-1]*10 + (s[i]-'0'))%a;
    }

    remb[n-1] = (s[n-1]-'0')%b;
    int p = 1;

    for(int i = n-2; i >= 0; --i){
        p *= 10, p %= b;
        remb[i] = (((s[i]-'0')*p)%b + remb[i+1])%b;
    }

    int ans_idx = -1;
    for(int i = 0; i < n; i++){
        if(rema[i] == 0 && remb[i+1] == 0){
            if(s[i+1] != '0'){
                ans_idx  = i;
                break;
            }
        }
    }



    if(ans_idx != -1 && (s.substr(ans_idx+1).length() > 0)){
        cout<<"YES\n";
        cout<<s.substr(0,ans_idx+1);
        cout<<endl;
        cout<<s.substr(ans_idx+1);
    }else
        cout<<"NO\n";



}
