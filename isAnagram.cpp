//
// Created by sark2 on 22-06-2019.
//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input the String s ant t. It should return true if t is
// and anagram of s, else should return false.
bool isAnagram(string s, string t) {
    // write your code here.
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return (s==t) ? true : false;


}

int main(int argc, char** argv){
    string s, t;
    cin>>s>>t;

    if (isAnagram(s, t)) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }
}
