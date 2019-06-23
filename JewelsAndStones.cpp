//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2 strings.
// It should return a integer value.
int numJewelsInStones(string& J, string& S) {
    //Write your code here
    unordered_set<char>set;
    for(auto i : J) set.insert(i);
    int res = 0;
    for(auto i : S){
        if(set.find(i) != set.end()) res++;
    }
    return res;
}
int main(int argc,char** argv){
    string J,S;
    cin>>J;
    cin>>S;
    int res=numJewelsInStones(J, S);
    cout<<res;
}