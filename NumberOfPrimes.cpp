//
// Created by sark2 on 19-06-2019.
//
#pragma GCC optimize("O3")

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)
#pragma GCC optimize("unroll-loops")

// -------------------</optimizations>--------------------)
#include <bits/stdc++.h>
using namespace std;
#define IOS  cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n)    for(int i = 1; i <= (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define cases int t;cin>>t;while(t--)
typedef long double ld;

typedef pair<int, int> pii;
//typedef vector<pii>vii;
typedef vector<int> vi;
typedef vector<long long> vll;
#define ll long long
#define inf LLONG_MAX
int SieveOfEratos(int n){

    bool isPrime[n+2];
    rep(i,n){
        isPrime[i] = true;
    }
    isPrime[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(isPrime[i]){
            for(int j = i; j <= n; j = j+i)
                if(j != i) isPrime[j] = false;
        }
    }
    int count = 0;
    rep(i,n){
        if(isPrime[i])count++;
    }
    return count;
}

int main(){
    IOS

    int n;
    cin>>n;
    cout<<SieveOfEratos(n);



}

