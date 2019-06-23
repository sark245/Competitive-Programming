//
// Created by sark2 on 21-06-2019.
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<int ,int>freq;

    int max = -1;
    freq[-1] = 0;
    for(auto i : s){
        freq[i-'0']++;
    }
    for(auto i : freq){
        if(i.second >freq[max]) max = i.first;
    }
    cout<<max;
}
