//
// Created by sark2 on 21-06-2019.
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+3];
    int x = 0 ;
    for(int i = 0; i < n ; i++){
        cin>>a[i];
        x ^= a[i];
    }
    cout<<x;



}
