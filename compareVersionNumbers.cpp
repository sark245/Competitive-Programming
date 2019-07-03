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

    string s1, s2;
    cin>>s1>>s2;

    stringstream c1(s1);
    stringstream c2(s2);
    string t1, t2;
    int l1 = 0, l2 = 0;
    while(getline(c1,t1,'.')&&getline(c2,t2,'.')){
       /* cout<<t1<<" : "<<t2<<endl;*/
        if(stoi(t1)>stoi(t2)){
            cout<<1;
            return 0;
        }
        else if(stoi(t1)<stoi(t2)){
            cout<<-1;
            return 0;
        }
    }
    c1.clear();
    c2.clear();

    while(getline(c1,t1,'.')){
        l1 += stoi(t1);
    }

    while(getline(c2,t2,'.')){
        l2 += stoi(t2);
    }

    if(l1==l2) {
        cout<<0;
        return 0;
    }

    else if(l1 > l2){
        cout<<1;
        return 0;
    }
    else cout<<-1;



}
