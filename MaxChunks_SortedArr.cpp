//
// Created by sark2 on 26-06-2019.
//

#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;

    int a[n+1];
    for(int i = 0; i < n; i++) cin>>a[i];

    int min_right[n+1];
    int max_left[n+1];

    max_left[0] = -1;
    for(int i = 1; i < n; i++){
        max_left[i] = max(max_left[i-1],a[i-1]);
    }
    min_right[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--){
        min_right[i] = min(min_right[i+1],a[i]);
    }

    int res = 0;

    for(int i = 0; i < n; i++){
       // cout<<min_right[i]<<" : "<<max_left[i]<<endl;
        if(min_right[i] >= max_left[i]) res++;
    }
    cout<<res;


}