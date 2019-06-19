//
// Created by sark2 on 19-06-2019.
//
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
#define IOS    cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
int subArraySum(vector<int> arr, int n, int sum){
    unordered_map<int,int>pfreq;
    pfreq[0]++;
    int s = 0;
    int ans = 0;
    for(auto i : arr){
        s += i;
        pfreq[s]++;
        if(pfreq.find(s-sum)!=pfreq.end())
            ans += (pfreq[s-sum]);

    }
    return ans;

}

int main(){
    IOS
    //Main Function
    int n;
    cin>>n;
    vector<int> arr;
    for (int z = 0; z < n; z++) {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    cout<<subArraySum(arr, n, 0);

}
