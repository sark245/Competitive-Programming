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

    string s;
    cin>>s;
    int ans = 0;
    int c = 1, p = 0;
    for(int i = 0; i < s.length(); i++){

        if(i >= 1 && s[i] != s[i-1]){
            p = c;
            c = 0;
        }
        if(i >= 1 && s[i] == s[i-1])c++;


        if(p >= c){
            ans += c;
        }


    }
    cout<<ans;
}
