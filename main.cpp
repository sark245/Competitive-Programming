//
// Created by sark2 on 18-06-2019.
//

#include<iostream>
#include "AdaptedStack1.h"
using namespace std;

#define rep(i,n) for(int i = 1; i<=n; i++)

int main(){
    AdaptedStack1 st;

    rep(i,10){
        st.ASpush(i);
    }

    rep(i,10){
        cout<<st.AStop()<<" ";
        st.ASpop();
    }
}