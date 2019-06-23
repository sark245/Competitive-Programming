//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input two arrays and lengths.
// It should print required output.
void solve(vector<long>& a, vector<long>& b,int n, int m)
{
    //Write your code here
    unordered_set<int>set;
    for(auto i : b) set.insert(i);

    for(auto i : a){
        if(set.find(i) == set.end()) cout<<i<<" ";
    }



}


int main(int argc,char** argv){
    int n ;
    cin>>n;
    vector<long> num(n);
    for (int i = 0; i < n; i++) {

        cin>>num[i];
    }
    int m;
    cin>>m;
    vector <long> num2(m);
    for (int i = 0; i < m; i++) {
        cin>>num2[i];
    }
    solve(num, num2, n, m);
}