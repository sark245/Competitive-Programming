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
// This function takes as input 2 arrays and m, n as lengths.
// It should return required output.
vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    //Write your code here
    vector<int>res;
    unordered_map<int,int>freq;
    for(auto i : nums1)freq[i]++;

    for(auto i : nums2){
        if(freq.find(i) != freq.end()){
            res.push_back(i);
            freq[i]--;
            if(freq[i]==0)freq.erase(i);
        }
    }


    return res;

}


int main(int argc,char** argv){
    int n ;
    cin>>n;
    vector<int> num1(n);
    for (int i = 0; i < n; i++) {

        cin>>num1[i];
    }
    int m;
    cin>>m;
    vector <int> num2(m);
    for (int i = 0; i < m; i++) {
        cin>>num2[i];
    }

    vector<int> res=intersect(num1, num2);
    if(res.empty())cout<<" ";
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}