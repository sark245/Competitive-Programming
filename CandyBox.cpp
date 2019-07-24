//
// Created by sark2 on 24-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

int main() {
    IOS
    cases{
        int n;
        cin>>n;
        unordered_map<int,int>freq;
        int a[n+1];
        for(int i = 0;i < n; i++){
            cin>>a[i];
            freq[a[i]]++;
        }
        map<int,int>mp;
        for(auto i : freq){
            mp[i.second]++;
        }
        stack<int>st;
        int ans = 0;
        int target = 1;
        for(auto i : mp){
            if(target == i.first){
                ans += i.first;
                while(i.second > 1 && !st.empty()){
                    ans += st.top();
                    st.pop();
                    i.second--;
                }
            }
            else{
                st.push(target);
                target++;
                ans += i.first;
                while(i.second > 1 && !st.empty()){
                    ans += st.top();
                    st.pop();
                    i.second--;
                }
            }


        }

    }


}
