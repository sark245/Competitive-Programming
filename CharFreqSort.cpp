//
// Created by sark2 on 19-06-2019.
//

#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
bool compare(const pair<int,char>&one, const pair<int,char>&two){

}
string frequencySort(string s) {
    //Write your code here
    unordered_map<char ,int>freq;
    for(auto i : s){
        freq[i]++;
    }
    priority_queue<pair<int,char>>q;
    for(auto i : freq){
        q.push({i.second,i.first});
    }
    string res ="";
    while(!q.empty()){
        int rep = q.top().first;
        while(rep--){
            res += q.top().second;
        }
        q.pop();
    }

    return res;


}

//Dont make changes here
int main(int argc, char** argv){
    string s;
    cin>>s;
    cout<<frequencySort(s);
}