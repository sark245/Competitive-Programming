//
// Created by sark2 on 21-06-2019.
//

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.

vector<string> topKFrequent(vector<string> words, int k) {
    //Write your code here
    int n = words.size();
    unordered_map<string,int>freq;
    for(auto i : words){
        freq[i]++;
    }

    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>p;

    int j = 0;
    for(auto i : freq){
        if(p.empty() || p.top().first < i.second || p.size()<k){
           // cout<<i.first<<" : "<<i.second<<endl;
            if(p.size() == k) p.pop();
           p.push({i.second,i.first});
       }

    }
    vector<string> res;
    while(!p.empty()){
        res.push_back(p.top().second);
        p.pop();
    }

    return res;



}

//Don't make any changes here
int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string val;
        cin>>val;
        arr.push_back(val);
    }
    int k;
    cin>>k;
    vector<string> res = topKFrequent(arr, k);
    sort(res.begin(), res.end());
    cout<<"[";
    for(int i=0; i<res.size(); i++){
        cout<<res[i];
        if(i != res.size() - 1){
            cout<<", ";
        }
    }
    cout<<"]";

}
