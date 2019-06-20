//
// Created by sark2 on 20-06-2019.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// --------------------------------------------------------
bool isTwoArrayEqual(vector<long> &num1, vector<long> &num2)
{
    // write your code here
    unordered_map<long,int>freq;
    for(auto i : num1){
        freq[i]++;
    }
    for(auto i : freq)cout<<i.first<<" "<<i.second<<endl;
    for(int i = 0; i <num2.size(); i++){
        freq[num2[i]]--;
    }
    for(auto i : freq)cout<<i.first<<" "<<i.second<<endl;
    for(auto i : freq){
        cout<<i.first<<" : "<<i.second<<endl;

    }
    return true;
}
// --------------------------------------------------------

int main()
{
    int n = 0;
    cin >> n;
    vector<long> num(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int m = 0;
    cin >> m;
    vector<long> arr(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    if (isTwoArrayEqual(num, arr))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}