//
// Created by sark2 on 18-06-2019.
//

#ifndef PEPCODING2_ADAPTEDSTACK1_H
#define PEPCODING2_ADAPTEDSTACK1_H
#include <bits/stdc++.h>
using namespace std;

class AdaptedStack1 {
    queue<int>data;
    queue<int>helper;
public:
    AdaptedStack1(){}
    void ASpush(int val){
        data.push(val); //Push in O(1)
    }

    void ASpop(){

        if(data.empty()){
            cout<<"Stack is Empty\n";
        }
        else {
            while (data.size() != 1) {
                helper.push(data.front());
                data.pop();
            }
            data.pop();
            while(!helper.empty()){
                data.push(helper.front());
                helper.pop();
            }
        }
    }
    int AStop(){
        if(data.empty()){
            return -1;
        }
        else {
            while (data.size() != 1) {
                helper.push(data.front());
                data.pop();
            }
            int ret = data.front();
            data.pop();
            helper.push(ret);
            while(!helper.empty()){
                data.push(helper.front());
                helper.pop();
            }
            return ret;
        }

    }


};


#endif //PEPCODING2_ADAPTEDSTACK1_H
