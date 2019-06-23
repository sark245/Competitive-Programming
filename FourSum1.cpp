// A hashing based CPP program to find if there are
// four elements with given sum.
#include <bits/stdc++.h>
using namespace std;
struct hash_pair{
    template <class T1, class T2>size_t operator()(const pair<T1,T2>& p)const{
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1^hash2;
    }
};
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};


// The function finds four elements with given sum X
vector<vector<int>> fourSum (vector<int> &arr, int X)
{
    // Store sums of all pairs in a hash table
    int n = arr.size();

    //To store all the O(n^2) pairs
    unordered_map<int,unordered_set<pair<int,int>,hash_pair>> mp;

    //Creates Sum vs Index Pair HashMap
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++) {

                mp[arr[i] + arr[j]].insert(make_pair(i,j));
        }
    for(auto i : mp){
        cout<<i.first<<" : ";
        for(auto j : i.second){
            cout<<"("<<j.first<<","<<j.second<<"), ";
        }
        cout<<endl;
    }



    unordered_set<string>v;
    //Find complimentary sums
    for(auto i : mp) {
        int sum = X - i.first;
        if (mp.find(sum) != mp.end()) {
            // cout<<i.first<<" : "<<sum<<endl;
            unordered_set<pair<int, int>, hash_pair> p = mp[sum];
            mp.erase(sum);
            for (auto j : i.second) {
                for (auto x : p) {
                    string ft;
                    //cout << j.first << " " << j.second << " " << x.first << " " << x.second << endl;
                    if (j.first != x.first && j.second != x.second && j.first != x.second && j.second != x.first) {
                        ft = to_string(j.first)+ to_string(j.second)+ to_string(x.first)+ to_string(x.second);
                        sort(ft.begin(),ft.end());
                        v.insert(ft);
                    }
                }
            }
        }
    }

    for(auto i : v)cout<<i<<endl;
     unordered_set<vector<int>,VectorHash>s;
   vector<vector<int>>res;
    for(auto i : v){
        vector<int>r;
        for(auto j : i){
            r.push_back(arr[stoi(string(1,j))]);
        }
        sort(r.begin(),r.end());
        s.insert(r);
    }
    for(auto i : s){
        res.push_back(i);
    }
    return res;

}

// Driver program to test above function
int main()
{
    int n, target;
    cin >> target >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> list = fourSum(nums, target);
    cout << "[";
    for (int i = 0; i < list.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < list[i].size(); j++)
        {
            if (j == list[i].size() - 1)
                cout << list[i][j];
            else
                cout << list[i][j] << ",";
        }
        if (i == list.size() - 1)
            cout << "]";
        else
            cout << "],";
    }
    cout << "]";
}
