//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input an array of integers.
// It should return 1 or -1.

int solve(vector<int>& arr) {
    // write your code here.
    unordered_map<int,queue<pair<int,int>>>map;
    for(int i = 0 ; i < arr.size()-1; i++){
        for(int j = i+1 ; j < arr.size(); j++){
            map[arr[i]*arr[j]].push({arr[i],arr[j]});
        }
    }
    for(auto i : map){
        if(i.second.size() > 1) {
            while (!i.second.empty()) {
                pair<int, int> p = i.second.front();
                i.second.pop();
                if (p.first != i.second.front().first && p.first != i.second.front().second &&
                    p.second != i.second.front().first && p.second != i.second.front().second)
                    return 1;

            }
        }
    }
    return -1;

}

//Don't make any changes here

int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int res = solve(v);

    if (res == 1) {
        cout<<"Found"<<endl;;
    } else if (res == -1) {
        cout<<"Not Found"<<endl;
    }


}