//
// Created by sark2 on 24-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring (string &s) {
    //Uses Valid-Invalid Approach
    //Steps are A*SR*

    int start = 0, end = 0; //Two Pointers
    unordered_set<char>set; //Set to check Uniqueness
    int res = 0;    //Stores Answer

    while(end != s.length()){

        while(set.find(s[end]) == set.end() && end != s.length()){  //Acquire Loop
            set.insert(s[end]);
            end++;
        }

        res = max(res,end-start);       //Settle loop

        while(set.find(s[end]) != set.end()){       //Release Loop
            set.erase(s[start]);
            start++;
        }

    }

    return res;


}

int main(int argc,char** argv){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
}