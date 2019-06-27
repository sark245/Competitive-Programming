//
// Created by sark2 on 27-06-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n)    for(int i = 1; i <= (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define cases int t;cin>>t;while(t--)
typedef long double ld;
string addBoldTag(string &s, vector<string>& dict){

    bool res[s.length()];
    memset(res,0, sizeof res);

    for(auto i : dict){
        size_t found = s.find(i);
        repA(j,found,found+i.length()-1){
            res[j] = true;
        }
    }
    int i = 0;
    string temp = s;
    s = "";
    while(i < temp.length()){
        cout<<i<<" : ";
        if(res[i]){
            s =   temp.substr(0,i) +  "<b>" + temp.substr(i, temp.length()-i);
            int j = i+1;
            while(res[j] && j < temp.length()){
                j++;
                cout<<j<<", ";
            }
            cout<<j<<", ";
            i = j;
            s = temp.substr(0,i) + "</b>" + temp.substr(i,temp.length()-i);
        }
        else i++;
    }

    return s;

}


int main() {
    IOS
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) {
        cin>>dict[i];
    }
    cout<<addBoldTag(s, dict);

}
