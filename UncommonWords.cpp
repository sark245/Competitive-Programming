//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
vector<string> uncommonFromSentences(string A, string B) {
    //Write your code here
    stringstream check1(A);
    stringstream check2(B);
    string token;

    unordered_map<string,int>freq;

    while(getline(check1,token,' ')){
        freq[token]++;
    }

    vector<string>res;
    while(getline(check2, token, ' ')){
       freq[token]++;
    }

    for(auto i : freq) {
       if(i.second == 1)
        res.push_back(i.first);
    }
    return res;
}

//Don't make any changes here
int main(int argc, char** argv){
    string A, B;
    getline(cin, A);
    getline(cin, B);

    vector<string> ans= uncommonFromSentences(A, B);
   // sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}