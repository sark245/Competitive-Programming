//
// Created by sark2 on 28-12-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int N = 2e5+10;

int n;
vector<int> a, cnt;

int solve_min(){
    int res = 0;
    for(int i = 0; i < n; i++){
        if(!cnt[i])continue;
        ++res;
        i += 2;
    }
    return res;
}

int solve_max(){
    int res = 0;
    int dist = 2;
    bool right = false;

    for(int i = 0; i < n; i++){
        if(!cnt[i]){
            ++dist;
            continue;
        }
        int j = i-1;
        int sum = 0;
        while(j+1 < n && cnt[j+1]){
            ++j;
            sum += cnt[j];  // Add all the consecutive terms
        }

        res += (j-i+1); // (j-i+1) is the length of the segment

        if(sum > j-i+1 && (!right || dist > 1)){
            --sum;
            ++res;
        }
        right = false;
        if(sum > j-i+1){
            right = true;
            ++res;
        }
        i = j;
        dist = 0;
    }
    return res;
}


int main(){
    cin>>n;
    a.resize(n);
    cnt.resize(n+1);

    for(int i = 0; i < n; i++){
        cin>>a[i];
        ++cnt[a[i]-1];
    }

    cout<<solve_min()<<" "<<solve_max();

}
