//
// Created by sark2 on 18-06-2019.
//

#include <bits/stdc++.h>
using namespace std;

void minTransfer(vector<int> heights) {
    // Write your code here
    int n = heights.size();
    unordered_map<int,int>map;
    for(auto i : heights){
        map[i] = 0;
    }

    for(auto i : heights){
        map[i] = map[i-1] + 1;
    }
    int m = -1;
    for(auto i : map)
    {
        if(i.second > m)m = i.second;
    }
    cout<<n-m;


}

//Dont make changes here
int main(int argc, char** argv) {
    int n;
    cin>>n;
    vector<int> heights;
    for (int i = 0; i < n; i++) {
        int val; cin>>val;
        heights.push_back(val);
    }
    minTransfer(heights);
}