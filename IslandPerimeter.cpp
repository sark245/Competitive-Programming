//
// Created by sark2 on 22-06-2019.
//

#include<iostream>
#include<string>
#include<vector>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input a matrix.
// It should return perimeter value.
int islandPerimeter(vector<vector<int> >& v)
{
    //Write your code here
    int ans = 0;
    for(int i = 0 ; i < v.size(); i++){
        for(int j = 0 ; j < v[0].size(); j++){
            if(v[i][j]==1){
                ans+=4;
                if( i < v.size()-1 && v[i+1][j] == 1) ans -= 2;
                if( j < v[0].size()-1 && v[i][j+1] == 1) ans -= 2;
            }
        }
    }

    return ans;
}
int main(int argc, char** argv){
    int row,col;
    cin>>row>>col;
    vector<vector<int> > v (row, vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cin>>v[i][j];
    }

    cout<<islandPerimeter(v);
}