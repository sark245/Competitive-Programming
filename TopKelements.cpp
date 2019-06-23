//
// Created by sark2 on 22-06-2019.
//
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
vector<int> topKFrequent(int n, vector<int> nums, int k) {
    //Write your code here
    vector<int> res;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    unordered_map<int,int>freq;

    for(auto i : nums)freq[i]++;

    for(auto i : freq){
        if(pq.empty() || pq.size() < k || pq.top().first < i.second){
            if(pq.size()==k)pq.pop();

            pq.push({i.second,i.first});
        }
    }

    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;








}

//Don't make any changes here.
int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    int k;
    cin>>k;
    vector<int> res = topKFrequent(n, arr, k);
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
