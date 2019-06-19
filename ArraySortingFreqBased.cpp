//
// Created by sark2 on 20-06-2019.
//
#include<bits/stdc++.h>
using namespace std;
struct compare {
    bool operator()(const pair<int, int> &p, const pair<int, int> &q) {
        if (p.first < q.first) return true;
        else if (p.first > q.first) return false;
        else {
            if (p.second > q.second) return true;
            else return false;
        }
    }
};
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
void sortByFreq(vector<int> arr, int n) {
    // Write your code here
    unordered_map<int,int>freq;
    priority_queue<pair<int,int>,vector<pair<int,int>>, compare>q;

    for(auto i : arr){
        freq[i]++;
    }
    for(auto i : freq){
        q.push({i.second,i.first});
    }
    while(!q.empty()){
        int rep = q.top().first;
        while(rep--){
            cout<<q.top().second<<" ";
        }
        q.pop();
    }

}

//Dont make changes here
int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        arr.push_back(val);
    }
    sortByFreq(arr, n);
}