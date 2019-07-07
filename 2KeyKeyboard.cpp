//
// Created by sark2 on 06-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

int keyboard(int n);
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}




int main() {
    IOS

    int n;
    cin>>n;

    cout<<keyboard(n);

}

unordered_map<int, int> findFactor(int n) {
    unordered_map<int,int >factors;

    while(n%2 == 0){
        factors[2]++;
        /*cout<<2<<" ";*/
        n/=2;
    }
    for(int i = 3; i*i <= n; i+=2){
        while(n%i==0){
            factors[i]++;
          /*  cout<<i<<" ";*/
            n/=i;
        }
    }
    if(n > 2){
        factors[n]++;
    }


    return  factors;
}

int keyboard(int n) {

    if(isPrime(n)){
        return n;
    }
    else{
        int ans = 0;
        unordered_map<int,int>factors = findFactor(n);

        for(auto i : factors){
            ans += i.first * i.second;
        }

        return ans;
    }
}
