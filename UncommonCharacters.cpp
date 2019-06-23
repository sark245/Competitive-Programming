//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
void uncommon(string str1, string str2) {
    //Write your code here, print required output.
    unordered_map<char,int>map;

    for(auto i : str1){
        map[i] = 1;
    }
    for(auto i : str2){
        if(map.find(i)==map.end()) map[i] = 2;
        else {
            if(map[i] == 1) map[i] = 3;

        }
    }

    string res;
    for(auto i : map){
        if(i.second == 2 || i.second == 1)res += string(1,i.first);
    }
    sort(res.begin(),res.end());
    cout<<res;

}

//Don't make any changes here
int main(int argc, char** argv){
    string str1, str2;
    cin>>str1>>str2;
    uncommon(str1, str2);
}