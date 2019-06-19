//
// Created by sark2 on 20-06-2019.
//
#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input two matrices and k.
// It should return the count of pairs with sum k.
int solve(vector<vector<int> > & mat1,vector<vector<int> >& mat2,int k) {
    // write your code here.
    unordered_map<int,int>f1,f2;

    for(auto i : mat1){
        for(auto j : i){
            f1[j]++;
        }
    }

    for(auto i : mat2){
        for(auto j : i){
            f2[j]++;
        }
    }
    int ans = 0;
    for(auto i : f1){
        if(f2.find(k-i.first) != f2.end()){
            ans += (i.second*f2[k-i.first]);
        }
    }
    return ans;

}


int main(int argc,char** argv){

    int n;
    cin>>n;
    vector< vector<int> > mat1(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat1[i][j];
        }
    }
    vector< vector<int> > mat2(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat2[i][j];
        }
    }
    int k;
    cin>>k;
    cout<<solve(mat1,mat2,k)<<endl;
}