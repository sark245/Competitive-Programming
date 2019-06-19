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
string smallestWindow(string s , string t) {

    int bs = -1, be = -1;

    unordered_set<char> set;
    for (auto i : t) {    //Create a Hash_set for second string
        set.insert(i);
    }

    unordered_map<char, int> freq;

    int i = 0;
    int start = 0, end = 0;
    while (end < s.length()) {
       // cout << "end : ";
        while (set.size() != freq.size() && end < s.length()) { //To find a valid window
            if (set.find(s[end]) != set.end()) {
                freq[s[end]]++;
            }

          //  cout << end << " ";
            end++;
        }
        //cout << endl;
        if (bs == be && bs == -1) {
            bs = start;
            be = end - 1;
        } else if (be - bs > end - start + 1) {
            bs = start;
            be = end - 1;
        }
        //cout<<"bs = "<<bs<<" be = "<<be<<endl;

       // cout << "start : ";
        bool flag = 0;
        while (set.size() == freq.size()) {    //Increment start to find better valid
            if (freq.find(s[start]) != freq.end()) {
                freq[s[start]]--;
                if (freq[s[start]] == 0) freq.erase(s[start]);
            }
          //  cout << start << " ";
            start++;
            flag = 1;
        }
        if(flag)start--;

        //cout << endl;
        if (be - bs > end - start +1) {
            bs = start ;
            be = end - 1;
        }
        //cout<<"bs = "<<bs<<" be = "<<be<<endl;
    }

    string res = s.substr(bs, be - bs + 1);
    return res;
}



int main(){
    IOS
    //Main Function
    string s1,s2;
    cin>>s1>>s2;
    cout<<smallestWindow(s1,s2);
}