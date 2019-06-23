
//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input two arrays and k.
// It should return list of k lists of pairs with smallest sum.
vector<vector<int> > kSmallestPairs(vector<int>& num1,vector<int> &num2 ,int k){
    // write your code here.
    vector<vector<int>>res;
    int i = 0, j= 0;

    while(i < num1.size()&& j < num2.size()){
            if(res.size()==k) break;
            vector<int>row;
            row.push_back(min(num1[i],num2[j]));
            row.push_back(max(num1[i],num2[j]));
            res.push_back(row);
            if(num1[i+1] > num2[j+1] || num2[j] == num2[j+1]) j++;
            else i++;
        }


    return res;





}

void display(vector<vector<int> > &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool sortcol( const vector<int>& l1,
              const vector<int>& l2 ) {
    int sum1 = l1[0] + l1[1];
    int sum2 = l2[0] + l2[1];

    if (sum1 != sum2) {
        return sum1 <sum2;
    } else {
        return l1[0]< l2[0];
    }

}
int main(int argc,char ** argv){

    int n;
    cin>>n;
    vector<int> num1;
    vector<int> num2;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num1.push_back(a);
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        num2.push_back(a);
    }

    int k;
    cin>>k;
    vector<vector<int> > res;
    res=kSmallestPairs(num1, num2, k);
    sort(res.begin(),res.end(),sortcol);
    display(res);
}