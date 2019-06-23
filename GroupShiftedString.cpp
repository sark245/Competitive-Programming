//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
// This is a functional problem. You have to complete this function.
// It takes as input the a string array. It return a list of list of
// strings of strings with same shifting sequence grouped together.

vector<vector<string> > groupStrings(vector <string>& strs){
    // write your code here.
    unordered_map<string,vector<string>>map;

    for(auto i : strs){
        string key;
        for(int j = 0 ; j < i.length()-1; j++){
            if(i[j+1]-i[j] < 0)key += (to_string(i[j+1]-i[j]+26) + "*");
            else key += (to_string(i[j+1]-i[j]) + "*");
        }
        map[key].push_back(i);
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
//function to sort the lists
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
    res=groupStrings(strs);
    for(vector<string> v:res){
        sort(v.begin(),v.end());
    }
    sort(res.begin(),res.end(),sortcol);
    display(res);
}