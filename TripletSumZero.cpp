//
// Created by sark2 on 23-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include <bits/stdc++.h>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array and n length of array.
// It should return a boolean value.
bool findTriplets(vector<int>&arr , int n)
{
    //Write your code here
    unordered_map<int,pair<int,int>>map;

    for(int i = 0 ; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            map[arr[i]+arr[j]] = {i,j};
        }
    }

    for(int i = 0 ; i < n; i ++){
        if(map.find(-1*arr[i]) != map.end()){
            if(map[-1*arr[i]].first != i && map[-1*arr[i]].second != i){
                return true;
            }
        }

    }
    return false;


}
//Don't make any changes here

int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    bool res = findTriplets(v,n);
    string ans=res==1?"true":"false";
    cout<<ans;

}