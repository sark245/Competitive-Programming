//
// Created by sark2 on 19-12-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int NMAX = 2014;
ll d1[2*NMAX], d2[2*NMAX], sol[2];

pair<int,int>v[2];

int board[NMAX][NMAX];

inline void Update(const int c, const int i, const int j, const ll val){
    if(val > sol[c]){
        sol[c] = val;
        v[c].first = i;
        v[c].second = j;
    }
}

int main() {

    int n; cin>>n;


    sol[0] = sol[1] = -1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
            d1[i+j] += board[i][j];     //Primary diagonal
            d2[i-j+n] += board[i][j];   //Secondary Diagonal
        }
    }

    //Two Bishops can be placed on two cells and not intersect if sum of their X and Y coordinates is
    // of different parity(odd or even)
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            //Update max for even sum and max for odd sum and their sum will be the answer
            Update((i+j)&1, i, j, d1[i+j]+d2[i-j+n]-board[i][j]);
        }
    }

    cout<<sol[0] + sol[1]<<"\n";

    if(v[0] > v[1])
        swap(v[0], v[1]);
    cout<<v[0].first<<" "<<v[0].second<<" ";
    cout<<v[1].first<<" "<<v[1].second<<" ";
    return 0;



}
