//
// Created by sark2 on 21-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array and k occurunces.
// Print id of customer which will be served first.
void solve(vector<int>& arr,int k) {
    // write your code here.
    unordered_map<int,int> freq;
    for(auto i : arr) freq[i]++;

    for(auto i : arr){
        if(freq[i]==k){
            cout<<i;
            return;
        }
    }
    cout<<-1;

}

//Don't make any changes here

int main(int argc,char** argv){

    int n,k;
    cin>>n;
    cin>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    solve(v,k);

}