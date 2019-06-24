//
// Created by sark2 on 24-06-2019.
//


#include<bits/stdc++.h>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2 strings
// It should return a boolean value

bool wordPattern(string &pattern, string &str) {
    //Write your code here
    unordered_map<char, string> map;
    unordered_map<string,char>mp;

    stringstream check(str);
    string token;
    int i = 0;
    while(i < pattern.length() && getline(check,token,' ')){
        if(map.find(pattern[i]) == map.end()){
            map[pattern[i]] = token;
            mp[token] = pattern[i];
        }
        else{
            if(map[pattern[i]] != token || mp[token] != pattern[i]){
                return  false;
            }
        }
        i++;
    }

    return true;
}


int main(int argc, char** argv){
    string pattern, str;
    cin>>pattern;
    cin.ignore();
    getline(cin,str);
    if(wordPattern(pattern,str)){
        cout<<"true";
    }else{
        cout<<"false";
    }
}