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

    string n;

    stack<char>st;
    bool ok1 = false, ok2 = false;

    for(char c : s){
        if(st.empty()){
            st.push(c);
        }else if(!ok1 && !ok2){
            if(st.top() == c){
                ok1 = true;
            }
            st.push(c);
        }else if(ok1 && st.top() != c){
            ok1 = false;
            ok2 = true;
            st.push(c);
        }else if(ok2 && st.top()!= c){
            ok2 = false;
            st.push(c);
        }
    }

    while(!st.empty()){
        n += string(1,st.top());
        st.pop();
    }

    reverse(n.begin(), n.end());
    cout<<n;

}
