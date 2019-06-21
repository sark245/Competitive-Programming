//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int count(vector<vector<int> > &a) {
    //Write your code here
    unordered_map<int,int>m,temp;
    for(auto i : a[0]){
        m[i]++;
    }
    for(auto i : a){
        for(auto j : i){
            if(m.find(j) != m.end() &&(temp.empty()||temp[j]<m[j]))
                temp[j]++;
        }
        m = temp;
        temp.clear();
    }
    return m.size();

}

//Don't make any changes here

int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<count(v)<<endl;
}