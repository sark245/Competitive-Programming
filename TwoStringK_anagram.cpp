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
bool areKAnagrams(string &str1, string &str2, int k)
{
    // write your code here
    unordered_map<char,int>freq;
    repA(i,0,str1.length()-1){
        freq[str1[i]]++;
    }
    repA(i,0,str2.length()-1){
        if(freq.find(str2[i]) != freq.end()){
             freq[str2[i]]--;
            if(freq[str2[i]] == 0) freq.erase(str2[i]);
        }
    }
    if(freq.size()<=k) return true;
    return false;
}
int main(){
    IOS
    //Main Function
    string s1, s2;
    cin >> s1 >> s2;
    int k = 0;
    cin >> k;

    if (areKAnagrams(s1, s2, k))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;


}