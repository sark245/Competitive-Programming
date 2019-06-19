//
// Created by sark2 on 20-06-2019.
//
#include <bits/stdc++.h>
using namespace std;

int MaxFreqGap(vector<int>v){

    unordered_map<int,int>freq;
    int M = -1;
    int m = INT_MAX;
    for(auto i : v){
        freq[i]++;
    }
    for(auto i : freq){
        if(i.second > M) M = i.second;
        if(i.second < m) m = i.second;
    }
    return M-m;
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    int val;
    for(int i = 0 ; i < n; i++){
        cin>>val;
        v.push_back(val);
    }

    cout<<MaxFreqGap(v);
}
