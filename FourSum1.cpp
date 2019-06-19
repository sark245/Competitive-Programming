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

// The function finds four elements with given sum X
vector<vector<int>> fourSum (vector<int> &arr, int X)
{
    // Store sums of all pairs in a hash table
    int n = arr.size();

    //To store all the O(n^2) pairs
    unordered_map<int,unordered_set<pair<int,int>,hash_pair>> mp;

    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++) {
            if(mp[arr[i] + arr[j]].find(make_pair(arr[j],arr[i])) == mp[arr[i]+arr[j]].end())
                mp[arr[i] + arr[j]].insert(make_pair(arr[i], arr[j]));
        }
   /* for(auto i : mp){
        cout<<i.first<<" : ";
        for(auto j : i.second){
            cout<<"("<<j.first<<","<<j.second<<"), ";
        }
        cout<<endl;
    }*/

    // Traverse through all pairs and search
    // for X - (current pair sum).
    vector<vector<int>>v;


    for(auto i : mp){
        int sum = X - i.first;
        if (mp.find(sum) != mp.end() && sum != i.first){
            cout<<i.first<<" : "<<sum<<endl;
                unordered_set<pair<int,int>,hash_pair> p = mp[sum];
                mp.erase(sum);
                for(auto j : i.second){
                    for(auto x : p) {
                        vector<int>ft;
                     if((j.first != x.first && j.second != x.second)||(j.first != x.second && j.second != x.first));
                        ft.push_back(j.first);
                        ft.push_back(j.second);
                        ft.push_back(x.first);
                        ft.push_back(x.second);
                        v.push_back(ft);
                    }
                }
            }

        }
    return v;
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
