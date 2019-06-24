//
// Created by sark2 on 21-06-2019.
//

#include <bits/stdc++.h>
using namespace std;
int main(){

    int n,k;
    cin>>n>>k;
    unordered_map<int,int>freq;
    int a[n+2];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        freq[a[i]]++;
    }

    for(auto i : freq){
        if(i.second < k ) {cout<<i.first; break;}

    }


}