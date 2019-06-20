//
// Created by sark2 on 20-06-2019.
//

#include <bits/stdc++.h>
using namespace std;
vector<string> subdomainVisits(vector<string> cpdomains) {
    //Write your code here
    unordered_map<string,int>freq;
    for(auto i : cpdomains){
        stringstream check(i);
        string count;
        getline(check,count,' ');
        int num = stoi(count);
        string token;
        stack<string>st;
        while(getline(check,token,'.')){
            st.push(token);
        }
        string temp ="";
        while(!st.empty()){
            if(temp.length() <= 1) temp = st.top();
            else
                temp = st.top()+ "." + temp ;
            st.pop();
            freq[temp] += num;
        }
    }
    vector<string>v;
    for(auto i : freq){
        v.push_back(to_string(i.second) + " " + i.first);
    }

    return v;

}

signed main(){
    int n;
    string sn;
    getline(cin, sn);
    n = stoi(sn);
    vector<string> cpd;
    string s;
    int i = 0;
    for(int i=0; i<n; i++) {
        string s;
        getline(cin, s);
        std::cout<<"";
        cpd.push_back(s);
    }
    vector<string> ans = subdomainVisits(cpd);
    sort(ans.begin(), ans.end());
    cout<<"[";
    bool flag = 0;
    for(string s : ans){
        if(!flag) {
            cout<<s;
            flag = true;
        }
        else
            cout<<", "<<s;
    }
    cout<<"]";
}