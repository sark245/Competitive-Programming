//
// Created by sark2 on 20-06-2019.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<unordered_map>

using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input the array and K.
// You have to return true if array can be divided, else should return
// false.

bool SubsetProblem(vector<int> arr1, vector<int> arr2)
{
    unordered_map<int,int>set;

    for(auto i : arr1){
        set[i]++;
    }


    for(auto i : arr2){

        if(set.find(i) != set.end()){
            set[i]--;
            if(set[i]==0)
            set.erase(i);
        }
        else if(set.find(i) == set.end()){

            return false;
        }
    }

    return true;

}

void solve()
{
    int n, m;
    cin >> n;

    vector<int> arr1(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cin>>m;
    vector<int> arr2(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    cout<<(SubsetProblem(arr1,arr2) ?  "Yes":"No")<<endl;

}

int main(int args, char **argv)
{
    solve();
    return 0;
}