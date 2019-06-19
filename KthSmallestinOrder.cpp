//
// Created by sark2 on 20-06-2019.
//

#include<iostream>
#include<vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input length of array, value of k and array of length n
// It should print k smallest elements in their original order
void print_k_smallest_elements_in_their_original_order(int n,int k, vector<int> arr){

}
// -----------------------------------------------------

int main(int argc, char** argv) {

    int n, k;
    cin>>n>>k;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    print_k_smallest_elements_in_their_original_order(n, k, arr);
}