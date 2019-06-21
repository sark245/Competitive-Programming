//
// Created by sark2 on 21-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;


//this is a functional problem
vector<string> commonChars(vector<string>& A){
    //write your code here
    unordered_map<char,int>m,temp;

    for(auto i : A[0]){
        m[i]++;
    }
    for(auto i : A){
        for(auto j : i){
            if(m.find(j) != m.end() && (temp.find(j)==temp.end() || m[j] > temp[j])){
                temp[j]++;
            }
        }
        m = temp;
        temp.clear();
    }
    vector<string>res;
    for(auto i : m){
        while(i.second--) {
            res.push_back(string(1, i.first));
        }
    }
    sort(res.begin(),res.end());
    return res;
}

void display(vector<string> &ans){
    cout<<"[";
    for(int j=0;j<ans.size();j++){
        cout<<ans[j];
        if(j!=ans.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}
int main(int argc,char ** argv){

    int n;
    cin>>n;
    vector<string> A;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        A.push_back(a);
    }
    vector<string> res;
    res=commonChars(A);
    sort(res.begin(),res.end());
    display(res);

}