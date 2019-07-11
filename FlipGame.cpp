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

    string s;
    cin>>s;
    vector<string>res;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '+'){
            if(s[i+1]=='+'){
                string temp = s;
                temp[i] = '-';
                temp[i+1] = '-';
                res.push_back(temp);
            }
        }

    }

    bool first = false;
    cout<<"[";

    for(auto i : res){
        if(!first){
            cout<<i;
            first = true;
        }
        else
            cout<<", "<<i;
    }
    cout<<"]";




}
