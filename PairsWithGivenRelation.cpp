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
    unordered_map<int,int>map;
    unordered_set<int>set;
    for(auto i : arr){
        set.insert(i);
    }
    unordered_set<int>::iterator it, jt;
    for(it = set.begin(); it != set.end(); ++it){
        for(jt = ++set.begin(); jt != set.end(); ++jt){
            map[*it * *jt]++;
        }
    }
    for(auto i : map){
        if(i.second > 1)return 1;
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
        cout<<"Found"<<endl;
    } else if (res == -1) {
        cout<<"Not Found"<<endl;
    }


}