//
// Created by sark2 on 20-06-2019.
//

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
bool containsDuplicate(vector<int> &nums) {
    //write your code here
    unordered_set<int>set;

    for(auto i : nums){
        if(set.find(i) != set.end()) return true;
        set.insert(i);
    }
    return false;

}
// -----------------------------------------------------



int main(int argc,char** argv){

    // Input for length of array.
    int N ;
    cin>>N;

    vector<int> v;

    // Input for array elements.
    for (int i = 0; i < N; i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }

    bool res=containsDuplicate(v);
    string ans=res==true?"true":"false";
    cout<<ans<<endl;
}