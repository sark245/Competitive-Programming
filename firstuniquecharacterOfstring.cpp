//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input a String s
// Return index of first unique character, if none present, return -1
int firstUniqChar(string& s) {
    // write your code here.
    unordered_map<char,int>freq;
    for(auto i : s)freq[i]++;
    for(int i = 0; i < s.length(); i++)if(freq[s[i]]==1)return i;
    return -1;
}

int main(int argc,char** argv) {

    string str;
    cin>>str;
    cout<<firstUniqChar(str);

}