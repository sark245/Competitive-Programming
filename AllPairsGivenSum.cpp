//
// Created by sark2 on 21-06-2019.
//

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& num1,vector<int> &num2 ,int k){
    //write your code here

    unordered_map<int,int>freq;
    for(auto i : num1){
        freq[i]++;
    }
    vector<pair<int,int>>pv;
    for(auto i : num2){
        if(freq.find(k-i) != freq.end()){
            pv.push_back({k-i,i});
            freq.erase(k-i);
        }
    }

    sort(pv.begin(),pv.end());
    bool flag = 0;
    for(auto i : pv){
        if(!flag) {
            cout << i.first << " " << i.second;
            flag = true;
        }
        else{
            cout<<", "<<i.first<<" "<<i.second;
        }
    }

}

int main(int argc,char ** argv){

    int n;
    cin>>n;
    int m;
    cin>>m;
    int k;
    cin>>k;
    vector<int> num1;
    vector<int> num2;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num1.push_back(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        num2.push_back(a);
    }

    print(num1, num2, k);
    cout<<endl;

}