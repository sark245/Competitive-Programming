#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input a String S. It should return true if the student could
// be rewarded, else should return false.
bool checkRecord(string &s) {
    // write your code here.

    auto found = s.find("LLL");
    if(found != string::npos)return false;
    int c = 0;
    for(int i = 0 ; i < s.length(); i++){
        if(s[i]=='A')c++;
    }
    if(c>1)return false;

    return true;
}

int main(int argc, char** argv){
    string S;
    cin>>S;

    if (checkRecord(S)) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }


}
