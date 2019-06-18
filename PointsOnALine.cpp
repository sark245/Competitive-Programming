#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

//you can use a comparator if you want
//write code here

struct hash_pair{
    template<class T1, class T2 >size_t operator()(const pair<T1,T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1^hash2;
    }
};
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int solve(vector<pair<int,int>>& points) {
    int n = points.size();

    vector<pair<int, int>>::iterator it, jt;
    int ans = -1;
    for (it = points.begin(); it != points.end(); ++it) {
        int m = -1;
        unordered_map<pair<int, int>, int, hash_pair> freq;
        for (jt = it + 1; jt != points.end(); ++jt) {
            int dy = jt->second - it->second;
            int dx = jt->first - it->first;
            int f = gcd(dx, dy);
            dx = dx / f;
            dy = dy / f;
            freq[make_pair(dx, dy)]++;
        }
        for (auto i : freq) {
            if (i.second > m) m = i.second;
        }
        ans = max(m, ans);
    }
    return ans+1;
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    int x, y;
    vector<pair<int, int>> points;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    cout << solve(points);
}