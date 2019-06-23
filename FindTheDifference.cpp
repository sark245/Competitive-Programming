//
// Created by sark2 on 23-06-2019.
//

#include<bits/stdc++.h>
#include<string>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input the String s ant t. It should return the different
// character.
char findTheDifference(string& s, string& t) {
    // write your code here.
    char res ;
    for(auto i : s) res ^= i;
    for(auto i : t) res ^= i;
    return res;

}
//Don't make any changes here

int main(int argc,char** argv){

    string s,t;
    cin>>s;
    cin>>t;
    cout<<findTheDifference(s,t)<<endl;
}