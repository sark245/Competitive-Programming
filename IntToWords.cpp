//
// Created by sark2 on 26-06-2019.
//

#include<bits/stdc++.h>
using namespace std;
string got[] = {
        "" , "Thousand", "Million", "Billion", "Trillion" };

string teen[] = {
        "", "One", "Two", "Three","Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen" };
string tens[] = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };


string f2(int num){


    string res;
    int o,t,h;
    o = num%10;
    num/=10;
    t = num%10;
    num/=10;
    h = num;

    if(h >= 1){
        if(t >= 2){
            return teen[h] +" "+ "Hundred " + tens[t] +" " + teen[o];
        }
        else{
            return teen[h] +" "+ "Hundred " + teen[t*10+o];
        }
    }
    else{
        if(t >= 2){
            return   tens[t] +" " + teen[o];
        }
        else{
            return    teen[t*10+o];
        }

    }


}


string f1(long long num, int level){
    if(num == 0) return "";

    return f1(num/1000, level+1) + f2(num%1000) +" "+ got[level] + " ";

}





int main(){

   long long n;
   cin>>n;
   cout<<f1(n,0);

}
