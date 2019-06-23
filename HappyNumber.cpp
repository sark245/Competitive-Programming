//
// Created by sark2 on 22-06-2019.
//
#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
// This is a functional problem. You have to complete this function.
// It takes as input a number n. It should return true if the number is
// happy, else should return false.
bool isHappy(int n) {
    // write your code here.
    int r;
    int curr = 0;
    int save = n;
    int temp = n;
    unordered_set<int>set;

    while(1){
        while(temp){
            r = temp%10;
            temp/=10;
            curr += r*r;
        }
        if(curr == 1)return true;
        if(set.find(curr) != set.end()) return false;
        else set.insert(curr);
        temp = curr;
        curr = 0;
    }


}





int main(int argc,char** argv) {
    int N;
    cin>>N;

    if (isHappy(N)) {
        cout<<"Happy"<<endl;
    } else {
        cout<<"Not Happy"<<endl;
    }
}