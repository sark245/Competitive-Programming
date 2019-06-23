//
// Created by sark2 on 21-06-2019.
//

#include<bits/stdc++.h>
using namespace std;
pair<int,int> TwoSum(vector<int>arr,int sum){

    pair<int,int>res;

    unordered_map<int,queue<int>>freq;
    for(int i = 0; i < arr.size(); i++){
        freq[arr[i]].push(i);
    }
    for(auto i : freq){

        if(freq.find(sum - i.first) != freq.end() ) {
            if ((sum - i.first) == i.first) {
                int p = i.second.front();
                i.second.pop();
                res = {p, i.second.front()};
            }
            else{
                res = {i.second.front() , freq[sum-i.first].front() };
            }
        }

    }



    return res;


}
int main(){
    int n;
    cin>>n;
    vector<int>arr;

    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        arr.push_back(val);
    }
    int sum ;
    cin>>sum;
    cout<<"[";
    pair<int,int> p = TwoSum(arr,sum);
    cout<<p.first<<", "<<p.second<<"]";

}