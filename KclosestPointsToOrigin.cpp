//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Do not change main
// This function takes as input a 2d array and k value
// It should return required output as 2d array
struct comparePoint{
    bool operator()(const pair<int,int>&p1 , const pair<int,int>&p2){
        if((p1.first*p1.first + p1.second*p1.second) > (p2.first*p2.first + p2.second*p2.second))
            return false;
        else return true;
    }
};
vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
    //Write your code here
    priority_queue<pair<int,int>,vector<pair<int,int>>,comparePoint>p;

    for(auto i : points){
        pair<int,int>pt;
        pt.first = i[0];
        pt.second = i[1];

        if(p.empty() || p.size() < K || (pow(p.top().first,2) + pow(p.top().second,2))>(pow(pt.first,2) + pow(pt.second,2))){
            if(p.size()==K) p.pop();
            else p.push(pt);
        }

    }
    vector<vector<int>>res;
    while(!p.empty()){
        vector<int>temp;
        temp.push_back(p.top().first);
        temp.push_back(p.top().second);
        p.pop();
        res.push_back(temp);
    }
    return res;

}
int main(int argc,char** argv){
    int row;
    cin>>row;
    vector<vector<int> > points(row,vector<int> (2));
    for(int i=0;i<row;i++){
        for(int j=0;j<2;j++){
            cin>>points[i][j];
        }
    }
    int k;
    cin>>k;
    vector<vector<int> > res=kClosest(points,k);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<2;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}