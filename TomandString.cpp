//
// Created by sark2 on 21-06-2019.
//

#include<iostream>
#include<vector>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
int getHashValue(string line) {
    //write your code here
    string s = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<char,int>pos;
   for(int  i = 0 ; i < s.length(); i++){
       pos[s[i]] = i;
   }

  stringstream check(line);
  string token;
  int cnt = 0 ;
  int ans = 0;
  while(getline(check,token,' ')){
      for(int i = 0; i < token.length(); i++){

          ans += (i+pos[token[i]]);
      }

      cnt++;
  }

  return ans*cnt;

}

int main(int argc, char** argv){
    string line;
    getline(cin, line);
    cout<<getHashValue(line);

}