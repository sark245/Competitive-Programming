//
// Created by sark2 on 20-06-2019.
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

string identifyString(string s){
    unordered_map<char,int>freq;
    for(auto i : s){
        freq[i]++;
    }
    priority_queue<pair<int,char>>q;

    for(auto i : freq){
        q.push({i.second,i.first});
    }

    string res = "";
    queue<pair<int,char>>q2;
   while(!q.empty()){
       pair<int, char>p = q.top();
       while(p.first == q.top().first ) {
           cout<<q.top().second<<" : "<<q.top().first<<endl;
            q2.push(q.top());
            q.pop();
       }
       while(!q2.empty()) {
           pair<int,char>p2 = q2.front();
           cout<<"Q2 : "<<q2.front().second<<" : "<<q2.front().first<<endl;
           q2.pop();
           res += string(1, p2.second);
           p2.first--;
           if(p2.first != 0 ){
               q.push(p2);
           }
       }
   }
    return res;



}
int main(){
    IOS
    string s;
    cin>>s;
    cout<<identifyString(s);

}