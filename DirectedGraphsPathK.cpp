//
// Created by sark2 on 15-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

vector<vector<int>> multiply(vector<vector<int>> one, vector<vector<int>> two){
    int n = one.size();
    vector<vector<int>>res(n,vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                res[i][j] += one[i][k]*two[k][j];
            }
        }
    }
    return res;
}

vector<vector<int>> raise(vector<vector<int>> m, int n){
    if(n==0){
        vector<vector<int>> zero(m.size(), vector<int>(m.size(),0));
        return zero;
    }

    if(n%2==0)
        return multiply(raise(m,n/2),raise(m,n/2));
    else{
        return multiply(m,multiply(raise(m,(n-1)/2),raise(m,(n-1)/2)));
    }
}


int main() {
    IOS
    int n;
    long long int k;
    cin>>n>>k;

    vector<vector<int>>a(n,vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin>>a[i][j];
        }
    }

    vector<vector<int>> f = raise(a,k);
    int c = 0;
    for(auto i : f){
        for(auto j : i){
            if(j==1)c++;
        }
    }
    cout<<c;



}
