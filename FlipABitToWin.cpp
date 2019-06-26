//
// Created by sark2 on 27-06-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n)    for(int i = 1; i <= (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define cases int t;cin>>t;while(t--)
typedef long double ld;

int main() {
    IOS
    int n;
    cin>>n;

    vector<bool>inp;
    bool val;
    rep(i,n){
        cin>>val;
        inp.push_back(val);
    }

    int start = 0, end = 0;
    //Play Valid-Invalid
    int res = 0;
    int zero_flag = 0;
    while(end <= n-1 && start <= n-1) {

        while (end <= n - 1 && (inp[end] || (zero_flag < 1))) {
            if (!inp[end]) zero_flag++;          //Acquire if end pointer is still in vector bounds
            end++;                              //Or the value is 1 or first 0
        }

        res = max(res, end - start);               //Settles the value if in invalid state

        while (zero_flag == 1) {                       //Releases till the (start, end] becomes valid
            if (!inp[start]) zero_flag--;
            start++;
        }
    }

    cout<<res;

}
