//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include<string>
using namespace std;
// --------------------------------------------------------------
// This is a functional problem. You have to complete this function.
// It takes as input a string array.
// It should print "Verified" if the username doesn't exists already,
//else should print the username with a number added to the end of the username.

void solve(vector<string> &str) {
    // write your code here
    unordered_map<string,int>freq;

    for(auto i : str){
        if(freq.find(i) == freq.end()){
            cout<<"Verified\n";
            freq[i]++;
        }
        else{
            cout<<i+to_string(freq[i])<<endl;
            freq[i]++;
        }
    }



}

int main(int argc,char** argv){
    // Length of the array
    int N ;
    cin>>N;
    vector<string> arr(N);
    for (int i = 0; i < N; i++) {
        cin>>arr[i];
    }

    solve(arr);
}