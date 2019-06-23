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
// This function takes as input two arrays and their lengths
// Print required output
void solve(vector<int>& a, vector<int>& b,int n, int m)
{
    //Write your code here
    unordered_map<int,int>set;
    for(auto i : a)set[i] = 0;
    int c = 0;

    for(auto i : b){
        if(set.find(i) != set.end()) {
            if(set[i] == 0) c++;
            set[i] = 1;
        }
    }
    cout<<c;

}


int main(int argc,char** argv){
    int n ;
    cin>>n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {

        cin>>num[i];
    }
    int m;
    cin>>m;
    vector <int> num2(m);
    for (int i = 0; i < m; i++) {
        cin>>num2[i];
    }
    solve(num, num2, n, m);
}