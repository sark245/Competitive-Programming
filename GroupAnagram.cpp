//
// Created by sark2 on 22-06-2019.
//
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
// This is a functional problem. You have to complete this function.
// It takes as input an array of Strings. It should return a list of list of strings
// with anagrams grouped together.

vector<vector<string> > groupAnagrams(vector <string>& strs){
    // write your code here.
    unordered_map<string,vector<string>>map;

    for(auto i : strs){
        string j = i;
        sort(j.begin(),j.end());
        map[j].push_back(i);
    }
    vector<vector<string>>res;

    for(auto i : map){
        sort(i.second.begin(),i.second.end());
        res.push_back(i.second);
    }

    return res;
}

void display(vector<vector<string> > &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool sortcol( const vector<string>& l1,
              const vector<string>& l2 ) {

    if (l1.size() != l2.size()) {
        return l2.size()<l1.size();
    } else {
        if(l1.size()==0){
            return false;
        }else{
            return l1[0]<l2[0];
        }
    }

}
int main(int argc,char ** argv){

    int n;
    cin>>n;
    vector<string> strs;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        strs.push_back(a);
    }

    vector<vector<string> > res;
    res=groupAnagrams(strs);
    for(vector<string> v:res){
        sort(v.begin(),v.end());
    }
    sort(res.begin(),res.end(),sortcol);
    display(res);
}
