//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include <bits/stdc++.h>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array of string.
// It should return an array of suitable strings.
string row1 = "qwertyuiopQWERTYUIOP";
string row2 = "asdfghjklASDFGHJKL";
string row3 = "zxcvbnmZXCVBNM";

vector<string> findWords(vector<string>& words) {
    //Write your code here
    unordered_map<char,int>map;
    for(auto i : row1) map[i] = 1;
    for(auto i : row2) map[i] = 2;
    for(auto i : row3) map[i] = 3;

    vector<string>res;
    for(auto i : words){
      int common = map[i[0]];
      bool flag = 0;
        for(int j = 1; j < i.length(); j++){
            if(map[i[j]] != common) flag = 1;
        }
        if(!flag) res.push_back(i);
    }
    return res;

}

int main(int argc,char** argv){
    int n;
    cin>>n;

    vector<string> words(n);
    for(int i=0;i<n;i++)
        cin>>words[i];

    vector<string>res;
    res= findWords(words);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";

}