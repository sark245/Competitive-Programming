//
// Created by sark2 on 21-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input the String s. It should return the first repeated
// character if present, else should return $.
char solve(string& s) {
    // write your code here.
    unordered_set<char>set;
    for(auto i : s){
        if(set.find(i) == set.end()) {
            set.insert(i);
        }
        else{
            return i;
        }
    }
    return '$';


}

int main(int argc,char** argv) {

    string str;
    cin>>str;
    cout<<solve(str)<<endl;

}