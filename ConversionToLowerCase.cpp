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
    string s;
    cin>>s;

    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i]<= 'Z'){
            int temp = s[i] - 'A';
            s[i] = 'a' + temp;
        }
    }
    cout<<s;


}
