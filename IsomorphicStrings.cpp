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
// It should return a boolean value.
bool isIsomorphic(string& s, string& t) {
    //Write your code here
    unordered_map<char,char>map;

    for(int i = 0 ; i < s.length(); i++){
        if(map.find(s[i])==map.end())
            map[s[i]] = t[i];
        else{
            if(map[s[i]] != t[i])return false;
        }
    }
    return true;


}
int main(int argc,char** argv){
    string A,B;
    cin>>A;
    cin>>B;
    bool res=isIsomorphic(A, B);
    if(res==0){
        cout<<"false";
    }else{
        cout<<"true";
    }
}
