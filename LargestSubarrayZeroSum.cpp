//
// Created by sark2 on 24-06-2019.
//

#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>arr){
    unordered_map<int,int>pos;

    int ps = 0, res = 0;
    pos[0] = -1;
    for(int i = 0; i < arr.size(); i++){

        ps += arr[i];

        if(pos.find(ps) != pos.end()){
            res = max(res,i-pos[ps]);
        }

        else{
            pos[ps] = i;
        }

    }
    return res;

}

int main(){
    int n;
    cin>>n;

    vector<int>arr;
    int val;
    for(int i = 0; i < n; i ++){
        cin>>val;
        arr.push_back(val);

    }
    cout<<solve(arr);

}