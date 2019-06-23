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
void subarraysDivByK(vector<int> A, int K) {

    //write your code here

    priority_queue<int,vector<int>,greater<int>> pq;

    for(auto i : A){
        if(pq.empty() || pq.size() < K || pq.top() < i){
            if(pq.size() == K) pq.pop();
            pq.push(i);
        }
        if(pq.size() == K) cout<<pq.top()<<" ";
        else cout<<-1<<" ";
    }


}


int main(int argc,char** argv){

    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    subarraysDivByK(v,k);

}