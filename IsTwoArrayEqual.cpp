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
    for(auto i : num2){
        freq[i]--;
    }
    for(auto i : freq){
        if(i.second != 0) return false;
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



    vector<long> arr(n, 0);
    for (int i = 0; i < n; i++)
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