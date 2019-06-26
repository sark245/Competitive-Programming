//
// Created by sark2 on 25-06-2019.
//
#include<bits/stdc++.h>
using namespace std;
int main(){

int n;
cin>>n;
int a[n+2];
    unordered_map<int,int>map;
for(int i =0; i < n; i++){
    cin>>a[i];
    map[a[i]]++;

}
int start = 0, end = 0;
int ans = 0;
int k = map.size();
map.clear();



while(end <= n-1){
    while(map.size()<k && end <= n-1){
        map[a[end]]++;
        end++;
    }

    while(map.size()==k){
        ans += (n-end+1);
        map[a[start]]--;
        if(map[a[start]]==0)map.erase(a[start]);
        start++;
    }
}

cout<<ans;


}
