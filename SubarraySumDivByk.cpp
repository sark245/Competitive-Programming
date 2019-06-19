//
// Created by sark2 on 20-06-2019.
//

#include<bits/stdc++.h>
using namespace std;

int subarrayDivK(vector<int>v,int k){
    unordered_map<int,int>freq;
    int s = 0;
    freq[0]++;
    for(auto i : v){
        s += i;
        if(s < 0) freq[(s%k+k)%k]++;
        else freq[s%k]++;
    }
    int ans = 0;
    for(auto i : freq){
        ans += ((i.second)*(i.second-1))/2;
    }
    return ans;

}
int main(){


    int n, k;
    cin>>n>>k;
    vector<int>v;
    int val;
    for(int i = 1; i <=n; i++){
        cin>>val;
        v.push_back(val);
    }
    cout<<subarrayDivK(v,k);
}