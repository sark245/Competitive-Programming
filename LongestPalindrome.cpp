//
// Created by sark2 on 24-06-2019.
//
#include <bits/stdc++.h>
using namespace std;
int longestPalindrome(string &str) {
    //Write your code here
    unordered_map<char,int>freq;
    for(auto i : str)freq[i]++;

    int ans = 0;
    bool flag = false;
    for(auto i : freq){
        if(i.second %2 == 0) ans += i.second;
        else{
            if(!flag){
                ans += (i.second);
                flag = true;
            }
            else ans += (i.second-1);
        }
    }

    return ans;
}

int main(int argc,char** argv){
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
}
