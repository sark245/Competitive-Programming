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

    string s;
    cin>>s;


    queue<pair<int,string>>generator;

    generator.push({1,"1"});
    while(!generator.empty()){
        //Push neighbours
        pair<int,string>p = generator.front();

        if(2*p.first <= n)
            generator.push({2*p.first,p.second + "0"});
        if(2*p.first+1 <= n)
            generator.push({2*p.first + 1, p.second + "1"});

        generator.pop();

        if((size_t)s.find(p.second) == string::npos){
            cout<<"false";
            return 0;
        }
    }


    cout<<"true";



}
