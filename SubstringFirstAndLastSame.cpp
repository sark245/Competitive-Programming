//
// Created by sark2 on 21-06-2019.
//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
int count(string str) {
    //Write your code here
    unordered_map<char,int>map;
    int ans = 0;
    for(int i = 0; i<str.length(); i++){
        map[str[i]]++;
        ans += map[str[i]];

    }
    return ans;


}

//Don't write your code here
int main(int argc, char** argv){
    string str;
    cin>>str;
    int ans = count(str);
    cout<<ans;
}
