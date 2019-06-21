//
// Created by sark2 on 21-06-2019.
//
#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int n){
    int i = 0;
    unordered_set<int>set;
    int j = 0;
    int res = 0;
    while(i < n){
        while(j<n && set.find(a[j]) == set.end() ){
            set.insert(a[j]);
            j++;
        }
        res += ((j-i)*(j-i+1))/2;
        set.erase(a[i]);
        i++;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int a[n+2];
    for(int i = 0; i < n ; i++) cin>>a[i];
    cout<<solve(a,n);


}
